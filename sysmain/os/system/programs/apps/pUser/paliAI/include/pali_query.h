#ifndef PALI_QUERY_H
#define PALI_QUERY_H

typedef enum {
    Q_WAKE_REASON,
    Q_MEM_STATUS,
    Q_CPU_STATE,
    Q_UNKNOWN
} pali_query_t;

pali_query_t pali_parse_query(const char *q);
void pali_dispatch_query(pali_query_t type);

#endif