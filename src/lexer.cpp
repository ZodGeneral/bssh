#include "lexer.hpp"

#include <cctype>
#include <string_view>
#include <vector>

namespace bssh {

std::vector<std::string_view> tokenize(std::string_view input) {
	std::vector<std::string_view> tokens;

	std::size_t pos = 0;

	while (pos < input.size()) {
		// Skip leading whitespace.
		while (pos < input.size() && std::isspace(static_cast<unsigned char>(input[pos]))) {
			++pos;
		}

		if (pos == input.size()) {
			break;
		}

		// Find the end of token.
		const std::size_t start = pos;

		while (pos < input.size() && !std::isspace(static_cast<unsigned char>(input[pos]))) {
			++pos;
		}

		tokens.emplace_back(input.data() + start, pos - start);
	}

	return tokens;
}

} // namespace bssh
