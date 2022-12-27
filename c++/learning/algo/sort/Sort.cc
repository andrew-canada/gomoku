#include <iostream>
#include <algorithm>
using namespace std;

int main()
{
    int arr[] = {11, 5, 8, 9, 6, 7, 3, 4, 2, 55};
    cout << sizeof(arr) << endl;
    cout << sizeof(arr[0]) << endl;
    int n = sizeof(arr) / sizeof(arr[0]);

    cout << sizeof(arr) << endl;
    cout << sizeof(arr[0]) << endl;
    cout << n << endl;
    cout << begin(arr) << endl;
    cout << *begin(arr) << endl;
    cout << end(arr) << endl;
    cout << *(end(arr) - 1) << endl;
    sort(begin(arr), end(arr));

    cout << "Array after sorting : \n";
    for (int i = 0; i < n; ++i)
        cout << arr[i] << " ";

    return 0;
}
