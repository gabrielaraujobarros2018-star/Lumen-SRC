#include <feedback.h>

void audio_ui_click(void) {
    audio_play("ui_click.wav");
}

void audio_ui_warning(void) {
    audio_play("ui_warning.wav");
}

void audio_ui_confirm(void) {
    audio_play("ui_confirm.wav");
}