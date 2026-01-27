/* PalisadeOS Asset Loader
 * OS-level, compile-unnecessary asset discovery and loading unit
 * Targets: /palisade/os/framework/framework.resourceX/assets/
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <stdint.h>
#include <sys/stat.h>

#define ASSET_ROOT "/palisade/os/framework/framework.resourceX/assets/"
#define MAX_PATH   512
#define MAX_ASSETS 1024

typedef enum {
    ASSET_UNKNOWN = 0,
    ASSET_IMAGE,
    ASSET_FONT,
    ASSET_AUDIO,
    ASSET_TEXT,
    ASSET_BINARY
} asset_type_t;

typedef struct {
    char path[MAX_PATH];
    asset_type_t type;
    size_t size;
    uint8_t *data;
} asset_t;

static asset_t asset_table[MAX_ASSETS];
static size_t asset_count = 0;

static int has_extension(const char *name, const char *ext) {
    size_t nlen = strlen(name);
    size_t elen = strlen(ext);
    if (nlen < elen) return 0;
    return strcmp(name + nlen - elen, ext) == 0;
}

static asset_type_t detect_type(const char *name) {
    if (has_extension(name, ".png")) return ASSET_IMAGE;
    if (has_extension(name, ".jpg")) return ASSET_IMAGE;
    if (has_extension(name, ".ttf")) return ASSET_FONT;
    if (has_extension(name, ".otf")) return ASSET_FONT;
    if (has_extension(name, ".wav")) return ASSET_AUDIO;
    if (has_extension(name, ".ogg")) return ASSET_AUDIO;
    if (has_extension(name, ".txt")) return ASSET_TEXT;
    return ASSET_BINARY;
}

static size_t file_size(FILE *f) {
    size_t cur = ftell(f);
    fseek(f, 0, SEEK_END);
    size_t size = ftell(f);
    fseek(f, cur, SEEK_SET);
    return size;
}

static uint8_t *read_file(const char *path, size_t *out_size) {
    FILE *f = fopen(path, "rb");
    if (!f) return NULL;
    size_t size = file_size(f);
    uint8_t *buf = (uint8_t *)malloc(size);
    if (!buf) {
        fclose(f);
        return NULL;
    }
    fread(buf, 1, size, f);
    fclose(f);
    if (out_size) *out_size = size;
    return buf;
}

static void register_asset(const char *path) {
    if (asset_count >= MAX_ASSETS) return;

    asset_t *a = &asset_table[asset_count];
    memset(a, 0, sizeof(asset_t));

    strncpy(a->path, path, MAX_PATH - 1);
    a->type = detect_type(path);

    size_t size = 0;
    uint8_t *data = read_file(path, &size);
    if (!data) return;

    a->size = size;
    a->data = data;

    asset_count++;
}

static void walk_directory(const char *base) {
    DIR *dir = opendir(base);
    if (!dir) return;

    struct dirent *ent;
    while ((ent = readdir(dir)) != NULL) {
        if (strcmp(ent->d_name, ".") == 0) continue;
        if (strcmp(ent->d_name, "..") == 0) continue;

        char full[MAX_PATH];
        snprintf(full, sizeof(full), "%s/%s", base, ent->d_name);

        struct stat st;
        if (stat(full, &st) != 0) continue;

        if (S_ISDIR(st.st_mode)) {
            walk_directory(full);
        } else if (S_ISREG(st.st_mode)) {
            register_asset(full);
        }
    }

    closedir(dir);
}

void assets_init(void) {
    asset_count = 0;
    walk_directory(ASSET_ROOT);
}

size_t assets_count(void) {
    return asset_count;
}

const asset_t *assets_get(size_t index) {
    if (index >= asset_count) return NULL;
    return &asset_table[index];
}

const asset_t *assets_find(const char *name) {
    for (size_t i = 0; i < asset_count; i++) {
        const char *p = strrchr(asset_table[i].path, '/');
        if (!p) continue;
        if (strcmp(p + 1, name) == 0)
            return &asset_table[i];
    }
    return NULL;
}

void assets_release(void) {
    for (size_t i = 0; i < asset_count; i++) {
        if (asset_table[i].data) {
            free(asset_table[i].data);
            asset_table[i].data = NULL;
        }
        asset_table[i].size = 0;
    }
    asset_count = 0;
}

const char *asset_type_name(asset_type_t t) {
    switch (t) {
        case ASSET_IMAGE: return "image";
        case ASSET_FONT: return "font";
        case ASSET_AUDIO: return "audio";
        case ASSET_TEXT: return "text";
        case ASSET_BINARY: return "binary";
        default: return "unknown";
    }
}

void assets_debug_dump(void) {
    for (size_t i = 0; i < asset_count; i++) {
        asset_t *a = &asset_table[i];
        printf("Asset %zu:\n", i);
        printf("  Path: %s\n", a->path);
        printf("  Type: %s\n", asset_type_name(a->type));
        printf("  Size: %zu bytes\n", a->size);
    }
}

int asset_is_loaded(const char *name) {
    return assets_find(name) != NULL;
}

size_t asset_size(const char *name) {
    const asset_t *a = assets_find(name);
    if (!a) return 0;
    return a->size;
}

const uint8_t *asset_data(const char *name) {
    const asset_t *a = assets_find(name);
    if (!a) return NULL;
    return a->data;
}

void assets_reload(void) {
    assets_release();
    assets_init();
}

void assets_for_each(void (*cb)(const asset_t *)) {
    if (!cb) return;
    for (size_t i = 0; i < asset_count; i++) {
        cb(&asset_table[i]);
    }
}

static void noop_callback(const asset_t *a) {
    (void)a;
}

void assets_self_test(void) {
    assets_for_each(noop_callback);
}

void assets_shutdown(void) {
    assets_release();
}