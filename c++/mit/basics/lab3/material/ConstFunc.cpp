#include <iostream>

using namespace std;

class Person
{
public:
    const int age = 5;
    const int constGetAge() const
    {
        return age;
    }
    int nonConstGetAge()
    {
        return age;
    }
};

int main()
{
    Person p1;
    cout << p1.constGetAge() << endl;
    // non const object can use const function
    cout << p1.nonConstGetAge() << endl;
    const Person p2;
    cout << p2.constGetAge() << endl;
    // const object can't use non const function
    // cout << p2.nonConstGetAge() << endl;
}