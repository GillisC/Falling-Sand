cmake_minimum_required(VERSION 3.10)

project(FallingSand)

set(CMAKE_CXX_STANDARD 17)

# Set default build type to Release if not specified
if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release CACHE STRING "Build type" FORCE)
endif()

# Add compiler flags for debugging
set(CMAKE_C_FLAGS_DEBUG "-g")
set(CMAKE_CXX_FLAGS_DEBUG "-g")

find_package(SDL2 REQUIRED)

# Include header files
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(headers)

add_executable(
    main 
    src/main.cpp
    src/grid.cpp
    src/sand.cpp
    )

target_include_directories(main PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(main PRIVATE ${SDL2_LIBRARIES})