#include <iostream>
#include <vector>
using namespace std;

/*
    Two ways to overload the constness of a const function and allow it to modify member variables
        1. Add "mutable" keyword when declaring the member variable
        2. Cast away the constness of the member variable inside the function
*/

class BigArray
{
private:
    vector<int> v;
    mutable int accessCount = 0; //allows accessCount to be modifiable in a const function
    //int accessCount = 0;

public:
    BigArray()
    {
        for (int i = 0; i < 10; i++)
        {
            v.push_back(i * 2);
        }
    }

    int getItem(int index) const
    {
        accessCount++;
        //const_cast<int &>(accessCount)++; //can cast away the constness of the member variablefor this line.
        return v[index];
    }
    int getAccessCount()
    {
        return accessCount;
    }
};

int main()
{
    BigArray ba;
    cout << ba.getItem(5) << endl;
    cout << ba.getItem(4) << endl;
    cout << ba.getItem(7) << endl;
    cout << ba.getItem(2) << endl;
    cout << ba.getItem(9) << endl;
    cout << ba.getAccessCount() << endl;
}