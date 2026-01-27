#include "pali_ai.h"
#include "pali_query.h"

static pali_ai_ctx_t g_ctx;

int pali_ai_init(pali_ai_ctx_t *ctx)
{
    if (!ctx)
        return PALI_AI_ERR;

    g_ctx = *ctx;
    g_ctx.flags = 0;
    return PALI_AI_OK;
}

int pali_ai_handle_query(const char *q)
{
    pali_query_t t = pali_parse_query(q);
    pali_dispatch_query(t);
    return PALI_AI_OK;
}

void pali_ai_shutdown(void)
{
    g_ctx.flags = 0;
}