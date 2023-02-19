#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int n;
    cin >> n;
    string name, wName;
    int mB = 0, b = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> name >> b;
        if (b > mB)
        {
            wName = name;
            mB = b;
        }
    }
    cout << wName << '\n';
}