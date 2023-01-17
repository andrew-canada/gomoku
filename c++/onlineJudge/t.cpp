#include <iostream>
#include <vector>

using namespace std;

int main()
{
    for (int i = 0; i < 3; ++i)
    {
        cout << i;
    }
    cout << "----\n";
    vector<vector<int>> numbers{{1, 2}, {3, 4}, {5}};
    cout << numbers.size() << '\n';
    cout << (1 << 1) << '\n';
}