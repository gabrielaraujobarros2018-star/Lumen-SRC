#include <stdint.h>

uint32_t dns_resolve_localhost(void) {
    return 0x7F000001; /* 127.0.0.1 */
}