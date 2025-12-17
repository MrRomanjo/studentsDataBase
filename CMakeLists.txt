cmake_minimum_required(VERSION 3.16)
project(students_database)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(students_database
        main.cpp
)

include(FetchContent)

FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/release-1.12.1.zip
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(students_database_tests
        tests.cpp
)

target_link_libraries(students_database_tests
        gtest
        gtest_main
)

add_test(NAME students_tests COMMAND students_database_tests)
