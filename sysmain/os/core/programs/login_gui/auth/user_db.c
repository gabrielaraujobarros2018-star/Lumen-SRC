#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <unistd.h>

#define DB_PATH "/palisade/data/users.db"
#define SCHEMA_VERSION 1

typedef struct {
    uint32_t schema;
    char username[32];
    uint8_t salt[16];
    uint8_t hash[32];
    uint8_t locked;
} user_record_t;

static void simple_hash(const char *pw, uint8_t *out) {
    for (int i = 0; i < 32; i++) {
        out[i] = (uint8_t)(pw[i % strlen(pw)] + i * 13);
    }
}

int user_create(const char *user, const char *pw) {
    FILE *f = fopen(DB_PATH, "ab");
    if (!f) return -1;

    user_record_t r = {0};
    r.schema = SCHEMA_VERSION;
    strncpy(r.username, user, sizeof(r.username) - 1);

    for (int i = 0; i < 16; i++)
        r.salt[i] = (uint8_t)(user[i % strlen(user)] ^ (i * 31));

    char salted[64];
    snprintf(salted, sizeof(salted), "%s%02x", pw, r.salt[0]);
    simple_hash(salted, r.hash);

    fwrite(&r, sizeof(r), 1, f);
    fclose(f);
    return 0;
}

int user_verify(const char *user, const char *pw) {
    FILE *f = fopen(DB_PATH, "rb");
    if (!f) return -1;

    user_record_t r;
    while (fread(&r, sizeof(r), 1, f)) {
        if (strcmp(r.username, user) == 0 && !r.locked) {
            uint8_t h[32];
            char salted[64];
            snprintf(salted, sizeof(salted), "%s%02x", pw, r.salt[0]);
            simple_hash(salted, h);
            fclose(f);
            return memcmp(h, r.hash, 32) == 0;
        }
    }
    fclose(f);
    return 0;
}