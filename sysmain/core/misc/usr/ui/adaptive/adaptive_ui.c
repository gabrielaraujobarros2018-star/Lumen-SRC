#include "../../include/userland.h"

void ui_adapt(struct ui_context *ctx) {
    if (!ctx) return;

    if (ctx->res.width >= 1920) {
        ctx->scale = 2;
    } else if (ctx->res.width >= 1280) {
        ctx->scale = 1;
    } else {
        ctx->scale = 0;
    }
}

uint32_t ui_scale(struct ui_context *ctx) {
    if (!ctx) return 0;
    return ctx->scale;
}