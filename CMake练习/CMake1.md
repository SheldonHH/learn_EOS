Here is a process to use CMake to create Makefile under linux environment

1. Write the configuration files `CMakeLists.txt`

2. Execute `cmake PATH` or `ccmake PATH` to create Makefile 

3. compile the code by using `make` 

   > the difference between `ccmake` and `cmake` is that cmake provide a interactive interface. Path is the directory where CMakeLists.txt exists

## Tutorial1

For simple project, we use `main.cpp` which is designed to solve square root of a number using [Newton method](https://en.wikipedia.org/wiki/Newton%27s_method) 

`main.cpp`

```cpp
#include <iostream>
#include <cmath>
using namespace std;
// use Newton method to find a square root of a certain number
double squareroot(double x)
{
    if(x == 0) return 0;
    double res = 1.0;
    double eps = 1e-12;

    while(abs(res*res - x) > eps){
        res = (res + x / res) / 2;
    }
    return res;
}

int main() // argc: # of parameters, argv: array of parameters
{
    int x;
    cout << "This program calculate a square root of a certain number." << endl;
    cout << "Please enter a number: " ;
    cin >> x;
    cout << "the square root of the input number x is: " << squareroot(x) << endl;
    return 0;
}
```

`CMakeList.txt`  is the input to the CMake build system for building software packages

```cpp
cmake_minimum_required(VERSION 2.8)

# name of the project Tutorial1
project(Tutorial1)

# create the executable binary makefile Demo1
add_executable(Tutorial1 main.cpp) 
```

##### Grammar of CMakeList.txt

The grammer of CMakeList.txt is consisted by command, comments, and space. Command is case-insensitive. The comments are the content after the `#` sign. The command is consisted with command name, parentheses and parameters. We separate parameters using space.

For example, to the file ` CMakeLists.txt` above , here are several commands:

1. `cmake_minimum_required`: indicate the minimum version required for the configuration files
2. `project`: specify the name of the project.
3. `add_executable` : we compile the main.cpp to a executable binary file called `Tutorial1`

##### Compilation of the project

Execute `cmake .` under the current directory,  it will generate the Makefile

use `make` command to generate the binary executable binary files





## Tutorial2: multiple source files in same directory

if we write the squareroot() to another source files called `MathFunctions.cpp` and a header file called `MathFunctions.cpp`

```
./2Tutorial
    |
    +--- main.cpp
    |
    +--- MathFunctions.cpp
    |
    +--- MathFunctions.hpp
    |
    +--- CMakeList.txt
```

include the MathFunctions in the `add_executable()`in the below：

`add_executable(Demo main MathFunctions)`





### 

## Tutorial3: multiple source files with multiple directories



e will use `aux_source_directory` to include all the source files in and save all the name of the sources  to the variable names

`aux_source_directory(<dir> <variable>)`

```
./3Tutorial
    |
    +--- main.cpp
    |
    +--- CMakeList.txt
    |
    +--- math/
          |
          +--- MathFunctions.cpp
          |
          +--- MathFunctions.hpp   
          |
          +--- CMakeList.txt    
  
```

We should have two different `CMakeList.txt` under both the 3Tutorial folder and math folder

##### CMakeList.txt under 3Tutorial

```
cmake_minimum_required (VERSION 2.8)

# project info
project (Tutorial3)

# check all the source files under the current directory
# Save all the name as 'DIR_SRCS'
aux_source_directory(. DIR_SRCS)

# add the subdirectory 'math' to the project
add_subdirectory(math)

# create the executable binary file 'Tutorial3' under the variable `DIR_SRCS`
add_executable(Tutorial3 ${DIR_SRCS})

# add the link libraries， 
# specify the library of "MathFunctions" to the target ""
target_link_libraries(Tutorial3 MathFunctions)
```

**`target_link_libraries`**: specify libraries or flags to use when linking a given target.

the target must be created by `add_executable()` and library must be created by `add_library()`

##### CMakeList.txt under math folder

```
# Collect all the source files under this directory, and stores in the list called DIR_LIB_SRCS
aux_source_directory(. DIR_LIB_SRCS)

# Specify the linker library of the MathFunctions
add_library(MathFunctions ${DIR_LIB_SRCS})
```





