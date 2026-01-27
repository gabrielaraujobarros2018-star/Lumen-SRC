#include "pali_query.h"
#include "pali_util.h"

/* forward declarations for report handlers */
extern void pali_report_wake(void);

/*
 * Parse a raw query string and map it to a
 * known system query type.
 */
pali_query_t pali_parse_query(const char *q)
{
    if (!q)
        return Q_UNKNOWN;

    if (pali_strcmp(q, "What woke the system?") == 0)
        return Q_WAKE_REASON;

    if (pali_strcmp(q, "Memory status") == 0)
        return Q_MEM_STATUS;

    if (pali_strcmp(q, "CPU state") == 0)
        return Q_CPU_STATE;

    return Q_UNKNOWN;
}

/*
 * Dispatch a parsed query to its handler.
 * No dynamic registration, no callbacks.
 * Deterministic switch-based routing.
 */
void pali_dispatch_query(pali_query_t type)
{
    switch (type) {

    case Q_WAKE_REASON:
        pali_report_wake();
        break;

    case Q_MEM_STATUS:
        pali_log("Memory status: unsupported");
        break;

    case Q_CPU_STATE:
        pali_log("CPU state: unsupported");
        break;

    default:
        pali_log("Query rejected: outside system scope");
        break;
    }
}