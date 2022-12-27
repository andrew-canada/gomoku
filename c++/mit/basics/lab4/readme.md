# templates, standard template library, operator overloading

## templates : template.cpp, templateParameter.cpp, templateSpecialize.cpp

- templates allow working with generic types - type not known ahead of time
  - write 1 template function instead of 5 functions with same application but different types (e.g., int addition, double addition)
- templates can be used with classes : template.cpp
- templates can be parametrized : templateParameter.cpp
- templates can be specialized for certain types : templateSpecialize.cpp
- templates can have default parameters 

## standard template library : templateSpecialize.cpp

- STL has container classes (e.g., maps, sets) and algorithms (sort, search)
- Use sets : useSets.cpp
- Array manipulation : useArray.cpp

## file handling : fileHandling.cpp, fileInput.txt, fileOutput.txt

- Like terminal input/output, but read from a file instead of cin, output to file instead of cout
  - #include <fstream>
  - input files represented by ifstream objects
  - output destination files represented by ofstream objects

## reading strings : readingStrings.cpp

- cin only reads to first whitespace
- getline(cin, STRINGNAME) reads everything until user presses enter

## enum : enum.cpp, connectFour.h, connectFour.cpp

- set of named integer values which are the only legal values of some new type
  - the first item defaults to 0
  - every other item defaults to the previous item + 1
  - enum members can be given a value of any type
  - scanf() can be used to input enum instance value

## exceptions : exceptions.cpp

- Functions can signal errors by throwing an exception
  - Causes function to exit immediately without return value
  - Calling function can catch exception (specify how it should be handled)
  - If not catched, the calling function exits immediately as well
  - Exception passes up from function to function on the call stack (chain of function calls that led to exception)
- Typically throw exception objects
  - inherit from class std::exception in header file < stdexcept >
- std exception classes have constructor taking a string that describes the problem
  - access with what() method
- alays use references when specifying catch block

## friend functions/classes : friendFunctionAndClass.cpp

- precede a function or class with "friend" to allow full access rights to private fields/methods of a class
  - write "friend" + signature in class
  - particularly common in operator overloading

## preprocessor macros : preprocessorMacros.cpp

- macro is like a small, non type-checked function - implemented by textual substitution
- defining macros is like defining constant

## casting : casting.cpp

- casting doesn't permanently change a variable's type
- C-style casts - 1/(double)4
  - Not recommended in c++
- c++ casting - cast type< type >(value)
  - More robust, more specification
  - types of casting:
    - static_cast - creates a copy of the value of the specified type
    - dynamic_cast - convert between pointer/reference types within an inheritance heirarchy
    - reinterpret_cast - treats memory containing value was though it were of different type (no actual conversion)
    - const_cast - modify const variable, make an object const

## TO DO
- Unions – group multiple data types together; unlike classes/structs, though, the fields of a union are mutually exclusive – only one of them is well-defined at any time
- Namespaces – allow you to wrap up all your code, classes, etc. into a “directory” of names, like std
- Advanced STL manipulation – allows you to do all sorts of wacky things with STL containers and iterators
- void pointers – pointers to data of an unknown type
- virtual inheritance – the solution to the “dreaded diamond” problem described in Lecture 8
- String streams – allow you to input from and output to string objects as though they were streams like cin and cout
- Run-time type information (RTTI) – allows you to get information on the type of a variable at runtime
- vtables – how the magic of virtual functions actually works
- stacks : https://en.wikipedia.org/wiki/Stack_(abstract_data_type)
- graphs: https://en.wikipedia.org/wiki/Graph_(abstract_data_type)

5.6
1. if constructors were private, no objects would be creatable
2. pointArr gets implicitly deallocated by default destructor, numberOfPolygons -= 1
3. polygon has protected fields so inherited classes (rectangle and triangle) can access fields (nothing else can access)
4. polygon version would get called because polyPtr is a Polygon * and getNumSides isn't virtual