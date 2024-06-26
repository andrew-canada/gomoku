#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int v, v1 = -1, v2 = -1, r, c, d;
    string s, s1, s2;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> r >> c >> d;
        v = 2 * r + 3 * c + d;
        if (v > v1)
        {
            v2 = v1, v1 = v;
            s2 = s1, s1 = s;
        }
        else if (v > v2)
        {
            v2 = v, s2 = s;
        }
    }
    if (v1 == v2)
    {
        if (s1 < s2)
        {
            cout << s1 << '\n'
                 << s2;
        }
        else
        {
            cout << s2 << '\n'
                 << s1;
        }
    }
    else
    {
        cout << s1 << '\n'
             << s2;
    }
}