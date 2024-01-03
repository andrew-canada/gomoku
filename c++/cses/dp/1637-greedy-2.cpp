#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    int steps = 0;
    while (n > 0)
    {
        string s = to_string(n);
        int dig = 0;
        for (char c : s)
        {
            dig = max(dig, c - '0');
        }
        n -= dig;
        steps++;
    }
    cout << steps;
}