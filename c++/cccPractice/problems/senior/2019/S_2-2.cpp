#include <bits/stdc++.h>

using namespace std;

bool prime(int a)
{
    for (int i = 2; i * i <= a; i++)
    {
        if (a % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        cin >> n;
        n *= 2;
        for (int a = 2; a < n; a++)
        {
            if (prime(a) && prime(n - a))
            {
                cout << a << " " << n - a << '\n';
                break;
            }
        }
    }
}