#include <iostream>

using namespace std;

int main()
{
    // explicit cast because bigger to smaller datatype
    int x = (int)5.0;
    cout << x << endl;

    // implicit cast because smaller to bigger datatype
    short s = 3;
    long l = s;
    cout << l << endl;

    float y = s + 3.4;
    cout << y << endl;
}