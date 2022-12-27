#include <iostream>
using namespace std;

/*
    1. Classes have default constructors if their constructor is empty or has a default value
    2. Compiler can create a constructor if there is no pre-written constructor
    3. If a class with a compiler-generated constructor has a member variable of another class with a constructor (not default),
        it will be unable to create the object of the class
*/

class Person
{
public:
    Person(string name = "joe")
    {
        cout << "person constructor" << endl;
    }
};

class Animal
{
private:
    int age;
    int *p1; //allowed
    //int &p2; //not allowed why? i don't know... i need to check

public:
    Animal()
    {
        cout << "animal constructor" << endl;
    }
};

class House
{
private:
    Person person;
    Animal animal;
    int age;

public:
    House() = default; //another way to create a default constructor
};

int main()
{
    House house1;
    cout << "hello" << endl;
}