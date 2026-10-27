cmake_minimum_required(VERSION 3.20)

project(bssh
	VERSION 0.1.0
	DESCRIPTION "Bite-Sized Shell"
	LANGUAGES CXX
)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)

add_executable(bssh
	src/main.cpp
	src/lexer.cpp
)

target_include_directories(bssh PRIVATE include)

target_compile_options(bssh PRIVATE
	-Wall
	-Wextra
	-Wpedantic
	-Wconversion
	-Wshadow
)

include(FetchContent)

FetchContent_Declare(
	googletest
	GIT_REPOSITORY https://github.com/google/googletest.git
	GIT_TAG v1.17.0
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(lexer_tests
	tests/lexer_tests.cpp
	src/lexer.cpp
)

target_include_directories(lexer_tests PRIVATE include)

target_link_libraries(lexer_tests PRIVATE GTest::gtest_main)

target_compile_options(lexer_tests PRIVATE
	-Wall
	-Wextra
	-Wpedantic
	-Wconversion
	-Wshadow
)

include(GoogleTest)
gtest_discover_tests(lexer_tests)
