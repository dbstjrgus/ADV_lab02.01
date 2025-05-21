cmake_minimum_required(VERSION 3.30)
project(ADV_Lab02_01)

set(CMAKE_CXX_STANDARD 20)
enable_testing()

include(FetchContent)

# Download GoogleTest
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/refs/heads/main.zip
)
FetchContent_MakeAvailable(googletest)

# Main exe
add_executable(ADV_Lab02_01
        main.cpp
        MorseBST.cpp
        MorseBST.h
        MorseTreeNode.cpp
        MorseTreeNode.h
)

# Copy the morsecode file to the build dir
configure_file("${CMAKE_CURRENT_SOURCE_DIR}/morsecode (1).txt"
        "${CMAKE_CURRENT_BINARY_DIR}/morsecode (1).txt" COPYONLY)

# Test exe
add_executable(morse_tests
        test.cpp
        MorseBST.cpp
        MorseBST.h
        MorseTreeNode.cpp
        MorseTreeNode.h
)

target_link_libraries(morse_tests
        gtest
        gtest_main
)

add_test(NAME MorseTests COMMAND morse_tests)
