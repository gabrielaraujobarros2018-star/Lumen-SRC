namespace palisade::gui::settings {

static int changed = 0;

void markChanged() {
    changed++;
}

int changeCount() {
    return changed;
}

}