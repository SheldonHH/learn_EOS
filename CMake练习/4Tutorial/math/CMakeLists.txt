# Collect all the source files under this directory, and stores in the list called DIR_LIB_SRCS
aux_source_directory(. DIR_LIB_SRCS)

# Specify the linker library of the MathFunctions
add_library(MathFunctions ${DIR_LIB_SRCS})

