#include <iostream>
using namespace std;

class House
{
public:
    House(string address)
    {
        cout << address << endl;
    }
    House(House &rhs) = delete;
};

class Building
{
private:
    string buildingName = "Building";
    Building(Building &rhs); //rhs is just a name, it can be anything

public:
    Building(string address)
    {
        cout << address << endl;
    }
};

int main()
{
    House h("earth");
    //House h2(h); //not allowed because line 11 disallow function
    Building b("moon");
    //Building b2(b); //not allowed because private copy constructor

    cout << "hello" << endl;
}