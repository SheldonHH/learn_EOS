# Classes (I)

Classes are an expanded concept of ***data structures***: like data structures, they can contain data members, but they can also contain functions as members.
An object is an instantiation of a class. In terms of variables, a class would be the type, and an object would be the variable.
Classes are defined using either keyword `class` or keyword `struct`, with the following syntax:



```c++
class class_name {
  access_specifier_1:
    member1;
  access_specifier_2:
    member2;
  ...
} object_names;
```

Where 

```
class_name
```

 is a valid identifier for the class, 

```
object_names
```

Where 

```
class_name
```

 is a valid identifier for the class, 

```
object_names
```

 is an optional list of names for objects of this class. The body of the declaration can contain 

members

, which can either be data or function declarations, and optionally 

access specifiers

.

Classes have the same format as plain 

data structures

, except that they can also include functions and have these new things called 

access specifiers

. An 

access specifier

 is one of the following three keywords: 

```
private
```

, 

```
public
```

 or 

```
protected
```

. These specifiers modify the access rights for the members that follow them:

- `private` members of a class are accessible only from within other members of the same class (or from their *"friends"*).
- `protected` members are accessible from other members of the same class (or from their *"friends"*), but also from members of their derived classes.
- Finally, `public` members are accessible from anywhere where the object is visible.