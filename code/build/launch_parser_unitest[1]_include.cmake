if(EXISTS "/Users/arika/Desktop/ShellRecorder/code/build/launch_parser_unitest[1]_tests.cmake")
  include("/Users/arika/Desktop/ShellRecorder/code/build/launch_parser_unitest[1]_tests.cmake")
else()
  add_test(launch_parser_unitest_NOT_BUILT launch_parser_unitest_NOT_BUILT)
endif()
