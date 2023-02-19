#include <iostream>
using namespace std;

int main()
{
    int speedLimit = 0, carSpeed = 0;
    cout << "Enter the speed limit: ";
    cin >> speedLimit;
    cout << "Enter the recorded speed of the car: ";
    cin >> carSpeed;
    int kmAboveLimit = carSpeed - speedLimit;

    if (kmAboveLimit <= 0)
    {
        cout << "Congratulations, you are within the speed limit!";
    }
    else if (kmAboveLimit >= 1 && kmAboveLimit <= 20)
    {
        cout << "You are speeding and your fine is $100.";
    }
    else if (kmAboveLimit >= 21 && kmAboveLimit <= 30)
    {
        cout << "You are speeding and your fine is $270.";
    }
    else
    {
        cout << "You are speeding and your fine is $500.";
    }
    return 0;
}