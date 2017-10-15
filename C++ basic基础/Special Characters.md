### Default constructor

default constructor is the constructor called when objects of a class are declared, but are not initialized with any arguments.

If a class definition has no constructors, the compiler assumes the class to have an implicitly defined 

default constructor

. Therefore, after declaring a class like this:

#### Destructors

Destructors fulfill the opposite functionality of *constructors*: They are responsible for **the necessary cleanup** needed by a class when its lifetime ends. The classes we have defined in previous chapters did not allocate any resource and thus did not really require any clean up.

But now, let's imagine that the class in the last example allocates dynamic memory to **store the string it had as data member**; in this case, it would be very useful to have a function called automatically at the end of the object's life in charge of releasing this memory. To do this, we use a *destructor*. A **destructor** is a member function very similar to a *default constructor*: it takes no arguments and returns nothing, not even `void`. It also uses the class name as its own name, but preceded with a tilde sign (`~`):



On construction, `Example4` allocates **storage** for a `string`. Storage that is later released by the destructor.

The destructor for an object is **called at the end of its lifetime**; in the case of `foo` and `bar` this happens at the end of function `main`.