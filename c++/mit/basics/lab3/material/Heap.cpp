#include <iostream>

using namespace std;

typedef long long ll;

ll *getPointer()
{
    ll *p = new ll;
    *p = 10;
    return p;
}

int main()
{
    ll *p;
    for (int i = 0; i < 1000000000; i++)
    {
        p = getPointer();
        cout << *p << endl;
        delete p; // delete when memory is no longer needed
    }
    // delete p; only deallocates the last pointer - wrong
    // delete p; don't delete twice
    return 0;
}