cmake_minimum_required(VERSION 3.10)

project(FallingSand)

find_package(SDL2 REQUIRED)

# Include header files
include_directories(${SDL2_INCLUDE_DIRS})
include_directories(headers)

add_executable(
    main 
    src/main.cpp
    src/grid.cpp
    )

target_link_libraries(main ${SDL2_LIBRARIES})