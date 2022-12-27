#include <iostream>
#include <string>

using namespace std;

class Wheel
{
private:
    string name;
    int size;
    int price;

public:
    Wheel(string name, int size, int price)
    {
        this->name = name;
        this->size = size;
        this->price = price;
    }
    void print()
    {
        cout << "Wheel name: " << name << endl;
        cout << "Wheel size: " << size << endl;
        cout << "Wheel price: " << price << endl;
    }
};

class Vehicle
{
protected:
    int year;
    string license;
    Wheel *wheel;

public:
    Vehicle(const string &inputLicense, const int inputYear)
        : license(inputLicense), year(inputYear) {}
    virtual const string getInfo() = 0;
    // {
    //     return license + " " + to_string(year) + '\n';
    // }
};

class Car : public Vehicle
{
private:
    int torque;

public:
    Car(const string &inputLicense, const int inputYear, const int inputTorque)
        : Vehicle(inputLicense, inputYear), torque(inputTorque) {}
    const string getInfo()
    {
        Wheel *wheel = new Wheel("Car Wheel", 20, 100);
        return license + " " + to_string(year) + " " + to_string(torque) + '\n';
    }
};

class Truck : public Vehicle
{
private:
    string type;

public:
    Truck(const string &inputLicense, const int inputYear, const string &inputType)
        : Vehicle(inputLicense, inputYear), type(inputType) {}
    const string getInfo()
    {
        return license + " " + to_string(year) + " " + type + '\n';
    }
};

void getInfoVehicle(Vehicle *v)
{
    cout << v->getInfo();
}

int main()
{
    // Vehicle v1("v1", 2018);
    // cout << v1.getInfo();
    Car c1("c1", 2018, 100);
    cout << c1.getInfo();
    Truck t1("t1", 2018, "type1");
    cout << t1.getInfo();

    // getInfoVehicle(&v1);
    getInfoVehicle(&c1);
}