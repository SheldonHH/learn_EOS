cmake_minimum_required (VERSION 2.8)
project (Tutorial5)

# -----------------------COLLECT SOURCES AND LIBRARY--------------------------
# collect all the sources file under the current folders and save the file names to DIR_SRCS variables
aux_source_directory(. DIR_SRCS)

# create the executable binary files
add_executable(Demo ${DIR_SRCS})
target_link_libraries (Demo  ${EXTRA_LIBS}) 


# --------------------------CONFIG OPTION--------------------------
# Add a configuration file config.hpp to handle the setting of CMake
# config.hpp provide the predefined parameters to monitor the creation of the code.
configure_file ( 
  "${PROJECT_SOURCE_DIR}/config.hpp.in"
  "${PROJECT_BINARY_DIR}/config.hpp"
  )

# --------------------------OPTION LOGICS--------------------------
# Provide the OPTION to choose that whether we want to use our defined "MathFunctions" library,  set default as "ON"
option (USE_MYMATH
       "Use provided math implementation" ON)

# If logic to decide
if (USE_MYMATH)
  include_directories ("${PROJECT_SOURCE_DIR}/math")
  add_subdirectory (math)  
  set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif (USE_MYMATH)




# ----------------------INSTALLATION CONFIG-----------------------------------
# Specify path of variable "DESTINATION"
install (TARGETS Demo DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/config.hpp"
         DESTINATION include)


#------------------------------TESTING-----------------------------------
enable_testing()

add_test(test_5 Demo 5)
# To test whether the information can be displayed properly
add_test(test_9 Demo 9)
set_tests_properties (test_9
 PROPERTIES PASS_REGULAR_EXPRESSION "is 3")


add_test(test_none Demo)


