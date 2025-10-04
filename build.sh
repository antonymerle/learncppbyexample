#!/bin/bash

# Compiler settings
CXX=clang++
CXXFLAGS="-std=c++23 -fcolor-diagnostics -fansi-escape-codes -g -pedantic-errors -Wall -Weffc++ -Wextra -Wconversion -Wsign-conversion -Werror"

# Filename
SOURCE=*.cpp
TARGET=learn

# Build and run
$CXX $CXXFLAGS $SOURCE -o $TARGET && ./$TARGET
