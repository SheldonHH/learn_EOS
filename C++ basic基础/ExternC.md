参考链接：https://stackoverflow.com/questions/67894/why-do-we-need-extern-c-include-foo-h-in-c

![](http://upload-images.jianshu.io/upload_images/3866441-b7406f05e62521d1.png?imageMogr2/auto-orient/strip%7CimageView2/2/w/1240)

C and C++ are superficially similar, but each compiles into a very **different set of code**. When you include **a header file** with a C++ compiler, the compiler is expecting C++ code. If, however, it is a C header, then the compiler expects the data contained in the header file to be compiled to a certain format—the C++ 'ABI', or 'Application Binary Interface', so the linker chokes up. This is preferable to passing C++ data to a function expecting C data.

(To get into the really nitty-gritty, C++'s ABI generally 'mangles' the names of their functions/methods, so calling `printf()` without flagging the prototype as a C function, the C++ will actually generate code calling `_Zprintf`, plus extra crap at the end.)

So: use `extern "C" {...};` when including a c header—it's that simple. Otherwise, you'll have a mismatch in compiled code, and the linker will choke. For most headers, however, you won't even need the `extern` because most system C headers will already account for the fact that they might be included by C++ code and already `extern` their code.









参考链接：https://stackoverflow.com/questions/1041866/in-c-source-what-is-the-effect-of-extern-c

extern "C" makes a function-name in C+**+ have 'C' linkage** (compiler does not mangle the name) so that client C code can link to (i.e use) your function using a 'C' compatible header file that contains just the declaration of your function. Your function definition is contained in a binary format (that was compiled by your C++ compiler) that the client 'C' linker will then link to using the 'C' name.

> **mangle**: destroy or severely damage by tearing or crushing.



Since **C++ has overloading of function names and C does not**, the C++ compiler cannot just use the function name as a unique id to link to, so it mangles the name by adding information about the arguments. A C compiler does not need to mangle the name since you can not overload function names in C. When you state that a function has extern "C" linkage in C++, the C++ compiler does not add argument/parameter type information to the name used for linkage.

Just so you know, you can specify "C" linkage to each individual declaration/definition explicitly or use a block to group a sequence of declarations/definitions to have a certain linkage



- extern "C" is a linkage-specification
- Every compiler is *required* to provide "C" linkage
- a **linkage specification** shall occur only in **namespace scope**
- ~~all function types, function names and variable names have a language linkage ~~**See Richard's Comment:** Only function names and variable names with external linkage have a language linkage
- two function types with distinct language linkages are distinct types even if otherwise identical
- linkage specs nest, inner one determines the final linkage
- extern "C" is ignored for class members
- at most one function with a particular name can have "C" linkage (regardless of namespace)
- ~~extern "C" forces a function to have external linkage (cannot make it static) ~~**See Richard's comment: **'static' inside 'extern "C"' is valid; an entity so declared has internal linkage, and so does not have a language linkage
- Linkage from C++ to objects defined in other languages and to objects defined in C++ from other languages is implementation-defined and language-dependent. Only where the object layout strategies of two language implementations are similar enough can such linkage be achieved