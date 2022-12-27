#include <iostream>

using namespace std;

class Vehicle
{
    virtual void print();
};

class Car : public Vehicle
{
public:
    void print()
    {
        cout << "Car" << endl;
    }
};

class Truck : public Vehicle
{
public:
    void print()
    {
        cout << "Truck" << endl;
    }
};

int main()
{
    int x = 5;

    // static cast
    cout << x / 10 << endl;
    // casting doesn't permanently change a variable's type
    // changes x into float for one line
    cout << static_cast<float>(x) / 10 << endl;

    // dynamic cast
    Car car1;

    Vehicle *vp = &car1;
    Car *car2 = dynamic_cast<Car *>(vp);
    car1.print();
    car2->print();

    Truck t1;
    Vehicle *vp1 = &t1;
    Truck *t = dynamic_cast<Truck *>(vp1);
    t->print();

    // reinterpret cast
    int *x1 = new int(65);
    cout << *x1 << endl;
    char *c1 = reinterpret_cast<char *>(x1);
    cout << *c1 << endl;

    // const cast
    int y = 0;
    cout << y << endl;
    const int *constPtr = &y;
    int *modifiable = const_cast<int *>(constPtr);
    *modifiable = 20;
    cout << y << endl;
}