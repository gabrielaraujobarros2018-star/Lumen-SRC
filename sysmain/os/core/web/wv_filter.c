#include <web.h>

int wv_filter_node(struct html_node *n) {
    if (!strcmp(n->tag, "script"))
        return 0;

    if (strstr(n->content, "tracker"))
        return 0;

    return 1;
}

void wv_apply_filters(struct webview *wv) {
    html_walk(wv->doc, wv_filter_node);
}