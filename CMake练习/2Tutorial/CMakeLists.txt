cmake_minimum_required(VERSION 2.8)

# name of the project
project(Tutorial2)

# 1. check all the source files under the current directory
# 2.  save the results as the variable names
add_executable(Tutorial2 main.cpp MathFunction.cpp) 

# create the target 
add_executable(Tutorial2 ${DIR_SRCS})