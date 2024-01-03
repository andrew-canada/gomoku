#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 2e5;

int main()
{
    ll n;
    cin >> n;
    int val;
    ll sum = 0;
    for (int i = 0; i < n - 1; i++)
    {
        cin >> val;
        sum += val;
    }
    cout << n * (n + 1) / 2 - sum;
}