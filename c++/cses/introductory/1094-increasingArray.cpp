#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int n;
    cin >> n;
    int cur, prev;
    if (n == 1)
    {
        cout << 0;
        return 0;
    }
    cin >> prev;
    ll moves = 0;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> cur;
        if (cur < prev)
        {
            moves += prev - cur;
            cur = prev;
        }
        prev = cur;
    }
    cout << moves;
}