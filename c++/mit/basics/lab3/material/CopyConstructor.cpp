#include <iostream>

using namespace std;

// with vs without copy constructor
// without copy constructor has errors

class IntArrayNoCC
{
public:
    int size;
    int *data;

    IntArrayNoCC(int size)
    {
        this->size = size;
        data = new int[size];
    }
    ~IntArrayNoCC()
    {
        delete[] data;
    }
};

class IntArrayWithCC
{
public:
    int size;
    int *data;

    IntArrayWithCC(int size)
    {
        this->size = size;
        data = new int[size];
    }
    IntArrayWithCC(IntArrayWithCC &input)
    {
        this->size = input.size;
        this->data = new int[size];
        for (int i = 0; i < size; i++)
        {
            this->data[i] = input.data[i];
        }
    }
    ~IntArrayWithCC()
    {
        delete[] data;
    }
};

int main()
{
    IntArrayNoCC noCC(3);
    noCC.data[0] = 1;
    noCC.data[1] = 2;
    noCC.data[2] = 3;
    if (true)
    {
        IntArrayNoCC noCC2 = noCC;
    }
    cout << noCC.data[0] << endl;

    IntArrayWithCC withCC(3);
    noCC.data[0] = 1;
    noCC.data[1] = 2;
    noCC.data[2] = 3;
    if (true)
    {
        IntArrayWithCC withCC2 = withCC;
    }
    cout << withCC.data[0] << endl;
}