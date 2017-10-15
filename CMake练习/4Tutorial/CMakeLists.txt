cmake_minimum_required (VERSION 2.8)
project (Tutorial4)

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
