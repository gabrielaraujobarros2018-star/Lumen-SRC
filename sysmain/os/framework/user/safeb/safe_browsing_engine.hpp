#pragma once
#include <string>

namespace palisade::features::safe {

bool isUrlSafe(const std::string& url);
void enableProtection(bool state);

}