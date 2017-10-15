cmake_minimum_required (VERSION 2.8)
project (Tutorial3)

# check all the source files under the current directory
# Save all the name as 'DIR_SRCS'
aux_source_directory(. DIR_SRCS)
add_subdirectory(math)

# create the executable binary file 'Tutorial3'
add_executable(Demo ${DIR_SRCS})

# add the link libraries
# specify the library of "MathFucn"
target_link_libraries(Tutorial3 MathFunctions)

