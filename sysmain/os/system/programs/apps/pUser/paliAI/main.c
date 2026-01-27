#include "include/pali_ai.h"

int main(void)
{
    pali_ai_ctx_t ctx;
    ctx.uptime_ms = 0;
    ctx.flags = 0;

    pali_ai_init(&ctx);
    pali_ai_handle_query("What woke the system?");
    pali_ai_shutdown();

    return 0;
}