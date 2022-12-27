# classes, OOP, memory management

## User-defined Datatypes : classes and structures

### classes : A user-defined datatype which groups together related pieces of information

- Fields indicate what related pieces of information our datatype consists of (aka members)
- Constructors: Method that is called when an instance is created
  - Default copy constructor : assigns one class instance to another (copies all fields) CopyConstructor.cpp
    - Default copy constructor for a class with pointer member points to same memory as original. If copy gets deallocated, original also gets deallocated
    - Custom copy constructor makes a COPY, different address. Original and copy are separate
  - When making an array of objects, default constructor is invoked on each ArrOfObj.cpp
  - When making a class instance, the default constructor of its fields are invoked ArrOfObj.cpp
  - Can invoke single-parameter constructor via assignment to the appropriate type ArrOfObj.cpp
  - Use default arguments to combine empty constructor and constructor with argument ArrOfObj.cpp
- Destructors: Deallocates a class
  - Invokes automatically when out of scope in stack memory
  - Manually invoke when not needed in heap memory
  - Can use default destructor or self-define with ~ character
- Static members and variables : value can change, but globally the same for each object of a class StaticMembers.cpp
  - Can only be referenced via the class : class methods, via a class instance (someObject.staticVariable), or via the className::variable construct StaticMembers.cpp
  - Always initalize static variable globally StaticMembers.cpp
  - If used in a header, to prevent compilation multiple times, only declare in header and initialize in cpp StaticMembers.cpp
- Static member functions StaticMembers.cpp
  - Can only access static member variables StaticMembers.cpp
  - Use when something should be consistant throughout all object instances (e.g, addition) StaticMembers.cpp
- Const and const member fuctions ConstFunc.cpp
  - Const function (const at beginning of signature) means it should be called on const objects : "read only" function ConstFunc.cpp
  - Const member function (const and end of signature) means it returns const values ConstFunc.cpp
  - A non const object can use a const function, but a const object can't use a non-const function

- Methods: functions which are part of a class

- An instance is an occurrence of a class. Different instances can have their own set of values in their fields.
- Pass by reference : PassByReference.cpp
- Pass by value : PassByValue.cpp

- member initializer syntax : This line demonstrates member initializer syntax. When defining a constructor, you sometimes want to initialize certain members,particularly const members, even before the constructor body. You simply put a colon before the function body, followed by a comma-separated list of items of the form dataMember(initialValue).

  ```c++
  Vehicle( const string &myLicense, const int myYear)
    : license(myLicense), year(myYear) {}
  ```

- strdup makes a copy of a char* (different memory address)

### structures

## OOP and Inheritance

- Encapsulation: grouping related data and functions together as objects and defining an interface to those objects
  - If someone hands us a class, we do not need to know how it actually works to use it (data hiding); all we need to know about is its public methods/data – its interface.
- Inheritance: allowing code to be reused between related types
  - If a member variable is declared as private, derived classes can't access it. Instead, declare as protected
  - Multiple inheritance : member of multiple classes
    - Best not to use : variable naming issues and inheritance from the same base class
    - Use "has a" approach instead of "is a" approach
- Polymorphism: allowing a value to be one of several types, and determining at runtime which functions to call on it based on its type
  - E.g., vehicle can be car type or truck type
  - If we have a function that expects a Vehicle object, we can safely pass it a Car object, because every Car is also a Vehicle.
  - Use virtual function to let Car use the Car version of function instead of Vehicle version
    - Pure virtual function : can't use abstract versions of function

### Is-a vs. Has-a

- Every A object has a B object. For instance, every Vehicle has a string object (called license).
- Every instance of A is a B instance. For instance, every Car is a Vehicle, as well.

## memory management

### scoping and memory

- When a variable goes out of scope, that memory is no longer guaranteed to store the variable’s value
  - A dangling pointer points to memory whose contents are undefined ScopingAndMemory.cpp

#### stack vs heap memory : Heap.cpp

- regular memory allocation is in stack memory
  - memory automatically deallocated when out of scope, no need to manually delete
- "new" keyword allocates memory in heap memory, rather than stack
  - memory needs to be manually deallocated by "delete" keyword

#### allocating arrays : AllocateArray.cpp

- same allocation method : use "new" and "delete" keyword, but add [] for array

#### allocating classes: AllocateClass.cpp

- same allocation method : use "new" and "delete" keyword, but can create custom destructor with ~ character

## string objects : StringObject.cpp

- In most cases, use string (with string library) instead of char * or char[].
  - Benefits: can modify length with operations, length not known ahead of time, more operations, etc.

## type conversions and constructors : TypeConversions.cpp

- Any time you call a function, the compiler will do its best to match the arguments you provide with some function definition. As a last-ditch strategy, it will even try constructing objects for you.
- Complier can convert an incompatable function or constructor argument to a suitable type. A double can turn into an object : TypeConversions.cpp

assignment 3 - 4.2

2.1 : line 21 can't double value because myPoint is const; line 20 no semicolon
2.2 : line 11 assignment is illegal because function is const body
2.3 : line 16 can't access member variables because private
2.4 : line 13 x is undefined in this scope. Should declare that setX is a member of Point class. I.e., Point::setX...
2.5 : line 10 needs delete[] because nums is an array
2.6 : add line at end of code to deallocate / delete Point p

4.5.1 : const and non-const versions are needed for different types of objects. const PointArray object needs const function. const function can prevent modifying when needed. non-const function can allow modifying.