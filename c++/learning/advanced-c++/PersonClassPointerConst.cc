#include <iostream>
using namespace std;

class Person
{
private:
    string name;
    int age;

public:
    Person(string name, int age)
    {
        this->name = name;
        this->age = age;
    }
    void getNameValue()
    {
        cout << "name value: " << name << endl;
    }
    void getNameValue() const
    {
        cout << "const name value: " << name << endl;
    }
    string &getNameReference()
    {
        cout << &name << endl;
        return this->name;
    }
    void getAgeValue()
    {
        getNameValue();
        cout << "age value: " << age << endl;
        age++;
    }
    void getAgeValue() const
    {
        getNameValue();
        cout << "const age value: " << age << endl;
        //age++; //not modifiable
    }
    const int &getAgeConst()
    {
        cout << &age << endl;
        return this->age;
    }
    void setAgeReference(const int &age)
    {
        this->age = age;
    }
};

int main()
{
    Person andrew("andrew", 5);
    andrew.getAgeValue();
    const Person bob("bob", 6);
    bob.getAgeValue();
    int referenceAge = 12;
    andrew.setAgeReference(referenceAge);
    andrew.getAgeValue();
    string &name = andrew.getNameReference();
    cout << &name << endl;
    cout << name << endl;
    const int &constAge = andrew.getAgeConst();
    cout << constAge << endl;
    //constAge++; //not allowed because const return type function
    cout << &constAge << endl;
    cout << constAge << endl;
    int abc = 5;
    int *point = &abc;
    cout << point << endl;
    cout << *point << endl;
    cout << point++ << endl;
    cout << *point << endl;
    return 0;
}