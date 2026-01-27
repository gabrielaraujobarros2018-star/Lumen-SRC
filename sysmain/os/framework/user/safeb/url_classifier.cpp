#include <string>

namespace palisade::features::safe {

int classifyUrl(const std::string& url) {
    if (url.find("http://") == 0) return 1;
    return 0;
}

}