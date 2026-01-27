#include <web.h>

void wv_init(struct webview *wv) {
    wv->loaded = 0;
}

int wv_load(struct webview *wv, const char *url) {
    if (!url) return -1;

    wv->doc = html_parse(url);
    wv->loaded = 1;
    return 0;
}

void wv_render(struct webview *wv) {
    if (wv->loaded)
        html_render(wv->doc);
}