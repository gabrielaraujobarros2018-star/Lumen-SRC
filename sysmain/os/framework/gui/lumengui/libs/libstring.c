int gui_strlen(const char* s) {
    int n = 0;
    while (s && s[n]) n++;
    return n;
}