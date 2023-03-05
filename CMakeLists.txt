cmake_minimum_required(VERSION 3.14)
project(code)

# GoogleTest requires at least C++14
set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS --coverage)

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
  input_parser_test
  ./tests/input_parser_test.cpp
  ./methods/input_parser.cpp 
  ./headers/input_parser.h
)
add_executable(
  launch_record_test
  ./tests/launch_record_test.cpp 
  ./methods/launch_record.cpp 
  ./headers/launch_record.h
)

add_executable(
  integration_test
  ./tests/integration_test.cpp
  ./methods/launch_record.cpp 
  ./headers/launch_record.h
  ./methods/input_parser.cpp 
  ./headers/input_parser.h
)

target_link_libraries(
  input_parser_test
  GTest::gtest_main
)

target_link_libraries(
  launch_record_test
  GTest::gtest_main
)

target_link_libraries(
  integration_test
  GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(input_parser_test)
gtest_discover_tests(launch_record_test)
gtest_discover_tests(integration_test)