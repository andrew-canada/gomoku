#include <iostream>

using namespace std;

class Area
{
public:
    int length, width;
    Area()
    {
        cout << "default" << endl;
    }
    Area(int l, int w)
    {
        cout << "with args" << endl;
    }
    ~Area()
    {
        cout << "destructor" << endl;
    }
};

int main()
{
    Area *a = new Area;
    if (true)
    {
        Area b(1, 2);
    }
    delete a;
}