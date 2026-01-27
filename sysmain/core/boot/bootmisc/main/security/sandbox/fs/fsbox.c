static int fs_restricted = 1;

void fsbox_open(void) {
    fs_restricted = 0;
}

int fsbox_isolated(void) {
    return fs_restricted;
}