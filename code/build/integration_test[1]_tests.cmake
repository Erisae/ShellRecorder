add_test([=[IntegrationTest.all]=]  /Users/arika/Desktop/ShellRecorder/code/build/integration_test [==[--gtest_filter=IntegrationTest.all]==] --gtest_also_run_disabled_tests)
set_tests_properties([=[IntegrationTest.all]=]  PROPERTIES WORKING_DIRECTORY /Users/arika/Desktop/ShellRecorder/code/build SKIP_REGULAR_EXPRESSION [==[\[  SKIPPED \]]==])
set(  integration_test_TESTS IntegrationTest.all)
