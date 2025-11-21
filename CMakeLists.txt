cmake_minimum_required(VERSION 3.10)

project(MerchantBusinessManagementSystem)

set(CMAKE_CXX_STANDARD 17)

# Include header files
include_directories(include)

# Collect all .cpp files automatically
file(GLOB SOURCES "src/*.cpp")

add_executable(MerchantBusinessManagementSystem ${SOURCES})
