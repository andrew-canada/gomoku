# Unit#1 java data type

## data types
 
 There are 2 categories of types
 - Primitive types: for storing simple values
 - Reference types/objects: for storing complex objects
 
### Primitive types

[Primitive data type tutorial](https://docs.oracle.com/javase/tutorial/java/nutsandbolts/datatypes.html)
 
 ap-cs-a com.andrew.primitive.types.PrimitiveTypes.java
 
 - primitive types are completely independent
 - value assigned will be held in a memory address
 - memory is allocated automatically by JRE
 
 Whole numbers with no decimal:
 - byte: 1 byte of memory - stores values from [-128, 127]
 - short: 2 bytes of memory - stores [-32K, 23K]
 - int: 4 bytes of memory - stores [-2B, 2B]
 - long: 8 bytes of memory
 
 Numbers with decimals:
 - float: 4 bytes of memory
 - double: 8 bytes of memory
 
 Characters:
 -char: 2 bytes of memory - stores [A, B, C
 
 Booleans (yes/no):
 - boolean: 2 bytes of memory - stores [true, false]
 
### Reference types
 
 - reference types are copied by the references
 - primitive types are copied by their values
 
-  reference types hold the memory address of a primitive types
![how reference types work[(reference-types.png)

### Strings

ap-cs-a com.andrew.reference.types.Strings.java

- parameters are the holes defined in the methods. e.g. name is a parameter: name: "andrew"
- arguments are the actual values passed to the methods. e.g. andrew is an argument: name: "andrew"
