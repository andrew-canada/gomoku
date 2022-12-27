# Java

## Java documentation

### JDK documentation

- [15](https://docs.oracle.com/en/java/javase/15/index.html)

## Java program structure

example: com.andrew.java.structure.HelloWorld.java

- Package: groups related classes
- Class: groups related functions/methods
- Functions/methods: performs tasks
  - Methods are the smallest components in a program
  - Main method is special. It is the entry point of a program

## How java code gets executed

- How java compiler works: source code (.java) -> java compiler -> bye code (.class)
	- invoke compiler: javac
	
	peng@LAPTOP-S3QD9J0T MINGW64 /c/work/projects/git-repo/andrew/ap-cs-a/src/com/andrew/java/structure (main)
	$ javac HelloWorld.java
	
- How JVM works: byte code (.class) -> JVM -> native code (Windows, Mac,...)
	- bin folder stores output for compiled code
	- each word in a package has a corresponding folder

	peng@LAPTOP-S3QD9J0T MINGW64 /c/work/projects/git-repo/andrew/ap-cs-a/bin (main)
	$ java com.andrew.java.structure.HelloWorld
	Hello World
 
## Variables
 
 e.g. ap-cs-a com.andrew.java.structure.HelloWorld.java
 
## Constants

e.g. com.andrew.variables.Constants.java
 
### how to define primitive type variable

if not assign a value, there is a default value, e.g. int will 0, boolean will be true

- int a; // default value is 0
- int a = 1;
- boolean a; // if not assign a value, there is a default value
- boolean a = false;

## Escape sequences

- [escape sequences](https://www.tutorialspoint.com/escape-sequences-in-java)
- e.g. com.andrew.java.escape.EscapeSequences.java

## Arrays

- single dimension example: com.andrew.java.arrays.SingleDimensionArrays
- multi dimension example: com.andrew.java.arrays.MultiDimensionalArrays

## Arithmetic Expressions

e.g. com.andrew.java.math.MathCalculations.java

## Casting

e.g. com.andrew.java.math.Casting.java