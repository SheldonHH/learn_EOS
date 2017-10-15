## Tutorial 4: Customize the compilation options

[Demo4](https://github.com/wzpan/cmake-demo/tree/master/Demo4)。

CMake allows to add the compile section for project, users can choose the best compilation solution based on environment and demands

For example, we can add option to library "MathFunctions", if the option is  `ON` ，we will use the math function of the our defined "MathFunctions" to compute square root, otherwise we will sue the math functions in the standard library <cmath>

```
./5Tutorial
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





*CmakeLists.txt*

```cmake
cmake_minimum_required (VERSION 2.8)

# Project Name
project (Tutorial4)

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
add_executable(Tutorial4 ${DIR_SRCS})
target_link_libraries (Tutorial4  ${EXTRA_LIBS}) 
```

To modify the `main.cpp` file, the pre-defined variable of **`USE_MYMATH`** is to to determine which library to use either <u>"standard library" or "MathFunctions"</u>



*main.cpp*

```c++
#include <iostream>
#include "config.h"  // created by "configuration_file()"
using namespace std;


#ifdef USE_MYMATH
	#include "math/MathFunctions.hpp"
#else
	#include <cmath>
#endif


int main() // argc: # of parameters, argv: array of parameters
{
    double x;
    double result;
    cout << "This program calculate a square root of a certain number." << endl;
    cout << "Please enter a number: " ;
    cin >> x;


  #ifdef USE_MYMATH
   		 printf("Now we use self-defined Math library. \n");
   		 result = squareroot(x);
	#else
	    printf("Now we use the <cmath> library. \n");
	    result = sqrt(x);
	#endif
    	cout << "the square root of the input number x is: " << result << endl;
	    return 0;

}
```



As shown in main.cpp, there is a preprocessor directives called `USE_MYMATH` but <u>we won't create the `config.h` directly</u> , insteadly we created a file called `config.h.in`

```hpp
#cmakedefine USE_MYMATH
```



*config.h.in*

这样 CMake 会自动根据 CMakeLists 配置文件中的设置自动生成 config.h 文件。

CMake will automately set the config.h



#### Compile the project

In order to choose the value of the paramter, we type `ccmake .` in the command prompt 

![Screen Shot 2017-08-28 at 10.07.43 AM](../../../../../Screen Shot 2017-08-28 at 10.07.43 AM.png)

We can view the option of `USE_MYMATH`,  we can change the option from 'ON' to 'OFF' by press the `enter` key to modify the option, subsequently, press `c` to confirm configuration, and press `g` to create the Makefile. ccmake 

Let's view the result after changing the result to `ON` and `OFF`



## Tutorial 5: Installation and Test Cases

CMake can also specify the installation rules and add test cases. The two fucntions can be executed using `make install` and `make test`. 

*math/CMakeList.txt*

```
# Specify the installation path for library: "MathFunctions" 
install (TARGETS MathFunctions DESTINATION bin)
install (FILES MathFunctions.h DESTINATION include)
```



CMakeList.txt

```
# Specify the path of config.h and the Destination path '/usr/local/bin'
install (TARGETS Demo DESTINATION bin)
install (FILES "${PROJECT_BINARY_DIR}/config.h"
         DESTINATION include)
```

Through the change in the two file above, the generated binary file Demo and the library `MathFunctions.o` will be copied to `/usr/local/bin/`  

the `MathFunctions.h` and `config.h` will be copied to `/usr/local/include/` 



###  Add the test cases for the engineer

CMake provide a testing tool called `add_test()` 

[add_test()](https://cmake.org/cmake/help/v3.0/command/add_test.html)

```
# start test
enable_testing()

# To test whether the information is shown successfully or not
add_test (test_usage Demo)
set_tests_properties (test_usage
  PROPERTIES PASS_REGULAR_EXPRESSION "Usage: .* base exponent")


# 测试 12 的平方
add_test (test_5_2 Demo 16)
set_tests_properties (test_16
 PROPERTIES PASS_REGULAR_EXPRESSION "correct return is 3")
 
 
# 测试 10 的 5 次方
add_test (test_10_5 Demo 10 5)
set_tests_properties (test_10_5
 PROPERTIES PASS_REGULAR_EXPRESSION "is 100000")
 
 
# 测试 2 的 10 次方
add_test (test_2_10 Demo 2 10)
set_tests_properties (test_2_10
 PROPERTIES PASS_REGULAR_EXPRESSION "is 1024")

```



## Tutorial 6: Use Macro to input data

```
# Define a macro to simplify the work
macro (do_test arg1 arg2 result)
  add_test (test_${arg1}_${arg2} Demo ${arg1} ${arg2})
  set_tests_properties (test_${arg1}_${arg2}
    PROPERTIES PASS_REGULAR_EXPRESSION ${result})
endmacro (do_test)
 
# test 
do_test (5 2 "is 25")
do_test (10 5 "is 100000")
do_test (2 10 "is 1024")
```





## Tutorial 7: Environment Check  

有时候可能要对系统环境做点检查，例如要使用一个平台相关的特性的时候。在这个例子中，我们检查系统是否自带 pow 函数。如果带有 pow 函数，就使用它；否则使用我们定义的 power 函数。

#### 添加 CheckFunctionExists 宏

首先在顶层 CMakeLists 文件中添加 CheckFunctionExists.cmake 宏，并调用 `check_function_exists` 命令测试链接器是否能够在链接阶段找到 `pow` 函数。



Sometimes we must check the environment before executing the program,  we need to create a file called  `CheckFunctionExists.cmake` and use `check_function_exists()` to verify whether the linker is able to connect to our function `squareroot`

```
include (${CMAKE_ROOT}/Modules/CheckFunctionExists.cmake)
```

