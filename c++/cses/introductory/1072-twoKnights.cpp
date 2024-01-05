#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        ll numGrid = i * i, numPlace = numGrid * (numGrid - 1) / 2;
        if (i > 2)
        {
            numPlace -= 4 * (i - 1) * (i - 2);
        }
        cout << numPlace << "\n";
    }
}