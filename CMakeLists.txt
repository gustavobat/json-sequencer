cmake_minimum_required(VERSION 3.9)
project(json_sequencer CXX)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

file(GLOB headers src/*.h src/*.hpp)
file(GLOB sources src/*.cpp)

set(main_SRCS ${sources} ${headers})
add_executable(json_sequencer ${main_SRCS})