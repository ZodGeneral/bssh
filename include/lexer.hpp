#pragma once

#include <string_view>
#include <vector>

namespace bssh {

[[nodiscard]]
std::vector<std::string_view> tokenize(std::string_view input);

} // namespace bssh

