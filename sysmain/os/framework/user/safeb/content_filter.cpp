namespace palisade::features::safe {

bool filterScriptContent(bool hasInlineScripts) {
    return !hasInlineScripts;
}

}