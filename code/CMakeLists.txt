cmake_minimum_required(VERSION 3.14)
project(shell-recorder)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)

include(FetchContent)
FetchContent_Declare(
  googletest
  URL https://github.com/google/googletest/archive/refs/tags/v1.13.0.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
  launch_parser_unitest
  ./test/launch_parser_unitest.cpp
)
target_link_libraries(
  launch_parser_unitest
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(launch_parser_unitest)