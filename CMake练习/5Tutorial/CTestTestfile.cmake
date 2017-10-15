# CMake generated Testfile for 
# Source directory: /Users/Sheldon/Desktop/EOS/决战Google/决战EOS/basic_eos/CMake练习/5Tutorial
# Build directory: /Users/Sheldon/Desktop/EOS/决战Google/决战EOS/basic_eos/CMake练习/5Tutorial
# 
# This file includes the relevant testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
add_test(test_5 "Demo" "5")
add_test(test_9 "Demo" "9")
set_tests_properties(test_9 PROPERTIES  PASS_REGULAR_EXPRESSION "is 3")
add_test(test_none "Demo")
subdirs("math")
