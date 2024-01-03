#include <bits/stdc++.h>

using namespace std;

int coins[9];

int main()
{
    int n;
    while (true)
    {
        cin >> n;
        if (!n)
        {
            return 0;
        }
        int val;
        for (int i = 0; i < n; i++)
        {
            cin >> coins[i];
        }
        if (n <= 1)
        {
            cout << 0 << '\n';
        }
        else if (n == 2)
        {
            if (coins[0] < coins[1])
            {
                cout << 0 << '\n';
            }
            else
            {
                cout << "IMPOSSIBLE\n";
            }
        }
        else
        {
            cout << "IMPOSSIBLE\n";
        }
    }
}