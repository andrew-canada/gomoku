#include <iostream>

using namespace std;

template <typename T, int N>
class TemplateArray
{
private:
    // initializes arr with size N - no constructor needed
    T arr[N];

public:
    void setValue(const int index, const T value)
    {
        arr[index] = value;
    }
    T getValue(const int index) const
    {
        return arr[index];
    }
};

int main()
{
    // creates new TemplateArray with size 2 - line 10; no constructor needed
    TemplateArray<int, 2> arr1;
    arr1.setValue(0, 43);
    cout << arr1.getValue(0) << endl;
}