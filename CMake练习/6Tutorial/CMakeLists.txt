cmake_minimum_required (VERSION 2.8)

# Project Name
project (Tutorial5)

# Add a configuration file config.h to handle the setting of CMake
# config.h provide the predefined parameters to monitor the creation of the code.
configure_file ( 
  "${PROJECT_SOURCE_DIR}/config.h.in"
  "${PROJECT_BINARY_DIR}/config.h"
  )

# Provide the OPTION to choose that whether we want to use our defined "MathFunctions" library,  set default as "ON"
option (USE_MYMATH
       "Use provided math implementation" ON)


# If logic to decide
if (USE_MYMATH)
  include_directories ("${PROJECT_SOURCE_DIR}/math")
  add_subdirectory (math)  
  set (EXTRA_LIBS ${EXTRA_LIBS} MathFunctions)
endif (USE_MYMATH)


# collect all the sources file under the current folders and save the file names to DIR_SRCS variables
aux_source_directory(. DIR_SRCS)


# create the executable binary files
add_executable(Demo ${DIR_SRCS})
target_link_libraries (Demo  ${EXTRA_LIBS}) 


# Specify the installation path
install (TARGETS Demo DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/config.h"
         DESTINATION include)



