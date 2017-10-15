https://en.wikipedia.org/wiki/Application_binary_interface



In [computer software](https://en.wikipedia.org/wiki/Computer_software), an **application binary interface** (**ABI**) is the [interface](https://en.wikipedia.org/wiki/Interface_(computing)) between two program modules, one of which is often a [library](https://en.wikipedia.org/wiki/Library_(computing)) and/or [operating system](https://en.wikipedia.org/wiki/Operating_system) and the other one is usually an application created by a regular programmer. In contrast to an [*API*](https://en.wikipedia.org/wiki/Application_programming_interface), which defines structures and methods one can use at **software level**, an *ABI* defines the structures and methods used to **access external**, *already compiled*libraries/code at the level of **[machine code](https://en.wikipedia.org/wiki/Machine_code)**. It does this by determining in which binary format information should be passed from one program component to the next, or to the operating system in the case of a [system call](https://en.wikipedia.org/wiki/System_call). Thus it sets details such as the [calling convention](https://en.wikipedia.org/wiki/Calling_convention).

Adhering to ABIs (which may or may not be officially standardized) is usually the job of the [compiler](https://en.wikipedia.org/wiki/Compiler), OS or library writer, but application programmers may have to deal with ABIs directly when writing programs in a mix of programming languages, using [foreign function call](https://en.wikipedia.org/wiki/Foreign_function_call) interfaces between them.

ABIs differ from [application programming interfaces](https://en.wikipedia.org/wiki/Application_programming_interface) (APIs), which similarly define interfaces between program components, but at the [source code](https://en.wikipedia.org/wiki/Source_code) level.

![](https://upload.wikimedia.org/wikipedia/commons/thumb/6/68/Linux_kernel_interfaces.svg/1536px-Linux_kernel_interfaces.svg.png)

