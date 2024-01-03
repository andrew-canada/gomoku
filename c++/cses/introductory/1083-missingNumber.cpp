#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 2e5;

bool found[mxN + 1];

int main()
{
    int n;
    cin >> n;
    int val;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> val;
        found[val] = true;
    }
    for (int i = 1; i <= n; i++)
    {
        if (!found[i])
        {
            cout << i;
            return 0;
        }
    }
}