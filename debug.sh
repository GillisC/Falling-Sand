#!/bin/bash

# Define build directory for debug
BUILD_DIR="build-debug"

# Create the build directory if it doesn't exist
if [ ! -d "$BUILD_DIR" ]; then
    mkdir "$BUILD_DIR"
fi

# Configure the project for Debug mode
cmake -S . -B "$BUILD_DIR" -DCMAKE_BUILD_TYPE=Debug

# Build the project in Debug mode
cmake --build "$BUILD_DIR"

# Run the program with gdb
echo "Starting gdb for debugging..."
gdb "$BUILD_DIR/main"