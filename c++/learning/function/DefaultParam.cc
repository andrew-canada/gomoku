#include <iostream>
using namespace std;

void defaultParam(string name, string city, int age = 0)
{
    cout << "Name: " << name << endl;
    cout << "City: " << city << endl;
    cout << "Age: " << age << endl;
}

int main()
{
    defaultParam("John", "New York");
    defaultParam("John", "New York", 25);
    return 0;
}