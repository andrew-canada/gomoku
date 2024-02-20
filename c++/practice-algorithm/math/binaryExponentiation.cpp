/*
break exponent into chunks (logN): 2^4 -> (2^2)^2 -> (2)^4
chaining: if computing a^b^c mod M, b^c must be mod (M-1) if M is odd (euler totient)
*/

#include <bits/stdc++.h>

using namespace std;

const int M = 1e9 + 7;

int mult(int b, int e, int m)
{
    int a = 1;
    while (e)
    {
        if (e & 1)
        {
            a *= b;
        }
        e >>= 1;
        b *= b;
    }
    return a;
}

int main()
{
    int b, e1, e2;
    cin >> b >> e1 >> e2;
    int x = mult(e1, e2, M - 1);
    cout << mult(e1, x, M);
}

/*
2 2 2
*/