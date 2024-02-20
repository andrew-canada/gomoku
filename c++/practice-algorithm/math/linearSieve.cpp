/*
linear sieve: finding divisors
1. check if multiples of a number with an added offset can reach a target
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxX = 100, M = 1e9 + 7;

int freq[mxX + 1];

int main()
{
    for (int i = 1; i <= mxX; i++)
    {
        for (int j = i; j <= mxX; j += i)
        {
            freq[j]++;
        }
    }
    int x;
    cin >> x;
    cout << freq[x] << '\n';
}

/*
8
*/