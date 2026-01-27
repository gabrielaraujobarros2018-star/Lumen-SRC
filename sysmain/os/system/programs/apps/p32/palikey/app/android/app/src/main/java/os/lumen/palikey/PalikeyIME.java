package os.palisade.palikey;

import android.inputmethodservice.InputMethodService;
import android.view.View;
import android.view.inputmethod.InputConnection;

public class PalikeyIME extends InputMethodService {

    @Override
    public View onCreateInputView() {
        View v = new View(this);
        v.setMinimumHeight(400);
        return v;
    }

    public void sendChar(char c) {
        InputConnection ic = getCurrentInputConnection();
        if (ic != null) {
            ic.commitText(String.valueOf(c), 1);
        }
    }

    public void backspace() {
        InputConnection ic = getCurrentInputConnection();
        if (ic != null) {
            ic.deleteSurroundingText(1, 0);
        }
    }
}