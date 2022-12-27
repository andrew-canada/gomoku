#include <iostream>

using namespace std;

class Integer
{
public:
    int val;
    Integer()
    {
        val = 0;
        cout << "default constructor " << val << endl;
    }
    Integer(int i)
    {
        val = i;
        cout << "single argument constructor" << val << endl;
    }
    // equivalent to combination of line 9 and 14 constructor : better practice
    // Integer(int v = 0)
    // {
    //     val = v;
    // }
    void setVal(int v)
    {
        val = v;
    }
};

class IntegerWrapper
{
public:
    Integer val;
    IntegerWrapper()
    {
        cout << "IntegerWrapper default constructor" << endl;
    }
};

int main()
{
    Integer arr[3];
    Integer a[] = {Integer(2), Integer(5)};
    a[0].setVal(3);
    IntegerWrapper intW;
    Integer int1 = 5;
    cout << "int1 value: " << int1.val << endl;
    Integer *heapArr = new Integer[3];
    delete[] heapArr;
}