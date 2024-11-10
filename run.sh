#!/bin/bash

if [ ! -d "build" ]; then
    mkdir build
fi

# Build the project
cmake -B build

# Compile the project

cmake --build build

# Run the executable
if [ $? -eq 0 ]; then
    echo "Build successful. Running the program..."
    echo "----------------------------------------"
    echo
    ./build/main
else
    echo "Build failed."
fi