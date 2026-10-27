#include "lexer.hpp"

#include <gtest/gtest.h>

#include <string>
#include <string_view>
#include <vector>

namespace {

using bssh::tokenize;

TEST(LexerTest, SplitWords) {
	const std::string input = "echo hello world";

	const auto tokens = tokenize(input);

	const std::vector<std::string_view> expected {
		"echo", "hello", "world"
	};

	EXPECT_EQ(tokens, expected);
}

TEST(LexerTest, HandlesRepeatedSpaces) {
	const std::string input = "echo   hello   world";

	const auto tokens = tokenize(input);

	const std::vector<std::string_view> expected {
		"echo", "hello", "world"
	};

	EXPECT_EQ(tokens, expected);
}

TEST(LexerTest, HandlesLeadingAndTrailingWhitespace) {
	const std::string input = "   echo hello   ";
	
	const auto tokens = tokenize(input);

	const std::vector<std::string_view> expected {
		"echo", "hello"
	};

	EXPECT_EQ(tokens, expected);
}

TEST(LexerTest, HandlesTabs) {
	const std::string input = "echo\thello\tworld";

	const auto tokens = tokenize(input);

	const std::vector<std::string_view> expected {
		"echo", "hello", "world"
	};

	EXPECT_EQ(tokens, expected);
}

TEST(LexerTest, HandlesEmptyInput) {
	const auto tokens = tokenize("");

	EXPECT_TRUE(tokens.empty());
}

TEST(LexerTest, HandlesWhitespaceOnlyInput) {
	const auto tokens = tokenize("   \t  \n ");

	EXPECT_TRUE(tokens.empty());
}

TEST(LexerTest, HandlesSingleToken) {
	const std::string input = "exit";

	const auto tokens = tokenize(input);

	ASSERT_EQ(tokens.size(), 1);
	EXPECT_EQ(tokens[0], "exit");
}

} // namespace
