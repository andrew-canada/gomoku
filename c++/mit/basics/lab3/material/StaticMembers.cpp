#include <iostream>

using namespace std;

class Person
{
public:
    // static member variable is globally the same for all instances of a class
    static int population;

    Person()
    {
        population++;
    }
    ~Person()
    {
        population--;
    }
    // manipulates a static variable
    static int getPopulation()
    {
        return population;
    }
};

// initialize the static variables
int Person::population = 0;

int main()
{
    Person p1;
    Person *p2 = new Person;
    Person p3[3];
    Person *p4 = new Person[4];
    cout << Person::getPopulation() << endl;
    delete p2;
    delete[] p4;
    cout << p1.getPopulation() << endl;
}