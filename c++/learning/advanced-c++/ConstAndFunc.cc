#include <iostream>
using namespace std;

class Dog
{
private:
    int age;
    string name;

public:
    Dog()
    {
        this->age = 3;
        this->name = "dummy";
    }
    Dog(int age, string name)
    {
        this->age = age;
        this->name = name;
    }
    int getAge()
    {
        return this->age;
    }
    void setAge(const /*without const, value of reference can be altered -> bad */ int &age)
    {
        this->age = age;
        //age++; //not allowed because age is const
    }
    //overloading function is possible because one is const and other isn't
    //input variable must be a const in order to call function with const parameter
    void setAge(int &age)
    {
        this->age = age;
    }
    string &getName()
    {
        cout << &name << endl;
        return this->name;
    }
    // if doesnt return a reference, variable address will be different
    string getNameValue()
    {
        cout << &name << endl;
        return this->name;
    }
    const string &getNameConst()
    {
        cout << &name << endl;
        return this->name;
    }
    void printDogAge() const
    {
        cout << age << endl;
    }
    void printDogName() const
    {
        //name = "andrew"; //not allowed because function is const
        //cout << getNameValue(); //const function can only call other const functions
        printDogAge(); //allowed because other function is also const
        cout << "const " << name << endl;
    }
    //overloading function is allowed because one is const and other is not
    //const fuctions are used when object is const
    void printDogName()
    {
        printDogAge(); //can call const fuction
        cout << "non-const" << name << endl;
    }
};

int main()
{
    Dog joe;
    cout << joe.getAge() << endl;
    Dog bob(1, "bob");
    cout << bob.getAge() << endl;
    int abc = 10;
    bob.setAge(abc);
    cout << abc << endl;
    cout << bob.getAge() << endl;
    abc = 9;
    cout << bob.getAge() << endl;

    //getName returns value -> different memory address
    string nameValue = bob.getNameValue();
    cout << &nameValue << endl;

    string &name = bob.getName();
    cout << &name << endl;
    cout << name << endl;
    cout << *&name << endl;
    name = "aa";
    cout << name << endl;

    const string &nameConst = bob.getNameConst();
    cout << &nameConst << endl;
    cout << nameConst << endl;

    // *nameConst = "aa"; //not allowed because const
    // cout << *nameConst << endl;

    int foo = 4;
    int *p1 = &foo;
    cout << p1++ << endl;
    cout << *p1 << endl;
    cout << p1-- << endl;
    cout << *p1 << endl;
    cout << "hello" << endl;

    bob.printDogName();

    const Dog constDog(7, "constDog");
    constDog.printDogName();

    int age = 9;
    bob.setAge(age);
    const int constAge = 10;
    bob.setAge(constAge);
    cout << "Hello" << endl;
}