#include <iostream>
using namespace std;

int getGreatestInt(double input)
{
    bool isInt = (input != int(input)) ? false : true;
    return ((input >= 0) ? (int)input : (isInt ? int(input) : int(input) - 1));
}
int main()
{

    srand(time(0));
    double d = rand();
    cout << "d is " << d << endl;
    cout << "greatest int is " << getGreatestInt(d) << endl;
    cout << "my balance is " << ((d <= 500) ? 10 : 10 - getGreatestInt(500 - d)) << endl;
}