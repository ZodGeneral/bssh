#include "lexer.hpp"

#include <iostream>
#include <string>

int main() {
	std::string input;

	while (std::getline(std::cin, input)) {
		const auto tokens = bssh::tokenize(input);
		
		for (const auto token : tokens) {
			std::cout << '[' << token << "]\n";
		}
	}
}

