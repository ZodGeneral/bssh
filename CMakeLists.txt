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
