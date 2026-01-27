namespace palisade::gui::locale {

static int lang = 0;

void setLanguage(int id) {
    lang = id;
}

int current() {
    return lang;
}

}