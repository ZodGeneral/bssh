#include <iostream>
#include <string>

int main() {
	std::string input;

	while (true) {
		std::cout << "bssh> " << std::flush;

		if (!std::getline(std::cin, input)) {
			std::cout << '\n';
			break;
		}

		if (input == "exit") {
			break;
		}

		if (input.empty()) {
			break;
		}

		std::cout << "You entered: " << input << '\n';
	}

	return 0;
}

