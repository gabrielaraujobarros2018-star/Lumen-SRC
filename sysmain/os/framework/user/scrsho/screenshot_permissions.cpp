namespace palisade::features::screenshots {

bool canCaptureScreen(bool isSecureSurface) {
    if (isSecureSurface) return false;
    return true;
}

void auditCaptureRequest() {
    // Logged to OS framework journal
}

}