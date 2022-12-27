# oo

##  objects, classes, packages

- object has state and behavior
	- state is modeled by fields
	- behavior is modeled by methods
- why use oo?
	- modularity
	- code re-use
	- information hiding
- place constructor call to another constructor directly after constructor signature
- non-static instance initializer
	- initializes an object's fields before constructor body
- instantiating an object
```java
JetEngine trent800 = new JetEngine("abc");
```
	1. new operator allocates memory for a new JetEngine object
	2. returns a reference to memory location and gives reference to trent800
	3. invokes constructor to create object
- destroying objects
	- garbage collection (gc)
		- automatic
		- customizable
		- nondeterministic
	- gc process
		1. mark - identify which objects are in use and which are not
			- gc roots - local variables, active java threads, static variables
			- goes up root until unreferenced object is found -> delete
		2. delete - remove unreferenced objects to free memory
		3. compact - OPTIONAL : compact remaining reference objects

## modeling state and behavior

- variables
	- 2 types
		- primitive
		- reference
	- 4 categories
		1. instance
			- object store individual state
			- used within class with getter and setter
		2. class
			- fields defined with "static"
			- can add "final" modifier : constant
		3. local
			- used by methods, only visible inside methods
		4. parameter
			- declared in method signatures
			- value provided by calling code
	- conventions
		- use nouns
- methods
	- 6 parts
		1. access modifier (optional)
		2. return type
		3. name
		4. parameter list (optional)
		5. exception list (optional)
		6. body
	- conventions
		- first word is verb because behavior
- passing information to method
	- field shadowing : constructor parameter has same name as class field (use "this" keyword)
	- arbitrary number of arguments (use carefully)
		- construct called varargs
		- shorthand for using an array
	```java
	public void printRoute(String...points){
		for (String point : points) {
			System.out.println(point);
		}
	}
	printRoute("B", "Y", "H");
	```
	- passing parameters
		- pass by value : use for primitive
		- pass by reference : use for reference types (e.g., objects)
	- parameter vs argument
		- parameter is variable
		- argument is value actually assigned to parameter
- "this" keyword
	- reference to current object

## static field, method, and class

- static modifier
	- final keyword makes global constant
	```java
	public static final int SPEED_OF_SOUND = 343;
	```
- static methods
	- can't use instance fields, only static fields
	- static initialization block : initialize class variables
	```java
	static {
		currentModelNb = 10;
	}
	```
- static nested classes
	- group related methods and variables within a class (if necessary)
	- can use when serializing (turn object to string and vv.) objects

## encapsulation, inheritance, and polymorphism

## exploring powerful java constructs

## reference
- understanding the java virtual machine: memory management - kevin jones
