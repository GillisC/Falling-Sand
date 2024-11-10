#!/bin/bash

# Define build directory for release
BUILD_DIR="build-release"

# Create the build directory if it doesn't exist
if [ ! -d "$BUILD_DIR" ]; then
    mkdir "$BUILD_DIR"
fi

# Configure the project for Release mode
cmake -S . -B "$BUILD_DIR" -DCMAKE_BUILD_TYPE=Release

# Build the project in Release mode
cmake --build "$BUILD_DIR"

# Run the program
echo "Running release version..."
"$BUILD_DIR/main"