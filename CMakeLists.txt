# Specify the minimum required version of CMake.
# This ensures that the version of CMake being used supports the required features.
cmake_minimum_required(VERSION 3.10)

# Define the name of the project.
# "RealmWeaver" is the name of your project. You can change this to anything you like.
project(RealmWeaver)

# Set the C++ standard to use (C++11 in this case).
# This ensures that your compiler will use the correct version of C++.
set(CMAKE_CXX_STANDARD 11)

# Include the header files from the "include" directory.
# This tells the compiler where to find header files during compilation.
include_directories(include)

# Find the CURL library. This searches for the required CURL package on your system.
# REQUIRED means that the CMake process will fail if CURL is not found.
find_package(CURL REQUIRED)

# Define the source files for your project.
# This variable "SOURCES" contains the path to your source files (in this case, "src/main.cpp").
set(SOURCES
    src/main.cpp
)

# Add an executable target. This tells CMake to generate an executable named "main"
# using the source files specified in the SOURCES variable.
add_executable(main ${SOURCES})

# Link against the CURL library.
# This ensures that the compiled program will be linked with the CURL libraries, which are required for using libcurl functions.
target_link_libraries(main ${CURL_LIBRARIES})
