#include <iostream>
using namespace std;

void variable()
{
    // cout << "Please enter your annual salary: ";
    // float salary;
    // cin >> salary;
    // float monthlySalary = salary / 12;
    // cout << "Your monthly salary is: " << monthlySalary << endl;
    // cout << "Your earnings after 10 years are: " << salary * 10 << endl;
    cout << "Size of int is " << sizeof(int) << " bytes." << endl;
    cout << "Size of float is: " << sizeof(float) << endl;
    cout << "Size of double is: " << sizeof(double) << endl;
    cout << "Size of char is: " << sizeof(char) << endl;
    cout << "Size of bool is: " << sizeof(bool) << endl;
    char gender = 'm';
    bool isOlderThan18 = true;
    int maxIntValue = INT_MAX;
    int minIntValue = INT_MIN;
    cout << "The maximum value of an int is " << maxIntValue << endl;
    cout << "The minimum value of an int is " << minIntValue << endl;
    cout << "The maximum value of an int + 1 is " << maxIntValue + 1 << endl;
    cout << "The minimum value of an int - 1 is " << maxIntValue - 1 << endl;
}

int main()
{
    variable();
}