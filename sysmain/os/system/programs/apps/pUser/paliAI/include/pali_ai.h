#ifndef PALI_AI_H
#define PALI_AI_H

#include <stdint.h>

#define PALI_AI_OK 0
#define PALI_AI_ERR -1

typedef struct {
    uint32_t flags;
    uint64_t uptime_ms;
} pali_ai_ctx_t;

int pali_ai_init(pali_ai_ctx_t *ctx);
int pali_ai_handle_query(const char *q);
void pali_ai_shutdown(void);

#endif