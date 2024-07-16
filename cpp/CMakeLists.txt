cmake_minimum_required(VERSION 3.12)
project(ladon)

set(CMAKE_CXX_STANDARD 11)

# Add the source files
file(GLOB SOURCES "src/*.cpp")

# Add the header files
file(GLOB HEADERS "headers/*.h")

# Add the executable
add_executable(ladon ${SOURCES} ${HEADERS})