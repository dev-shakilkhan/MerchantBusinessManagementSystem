cmake_minimum_required(VERSION 3.10)
project(MerchantBusinessManagementSystem)

# Use C++17 standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include directories
include_directories(include)

# Collect all source files
file(GLOB SOURCES "src/*.cpp")

# Create executable
add_executable(MBMS ${SOURCES})

# Optional: compiler warnings
if(MSVC)
    target_compile_options(MBMS PRIVATE /W4 /WX)
else()
    target_compile_options(MBMS PRIVATE -Wall -Wextra -Wpedantic -Werror)
endif()
