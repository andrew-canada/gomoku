#include <bits/stdc++.h>

typedef long long ll;
#define A 10 ^ 9 + 7

unsigned long long factorial(int n)
{
    const unsigned int M = 1000000007;

    unsigned long long f = 1;
    for (int i = 1; i <= n; i++)
        f = (f * i) % M; // Now f never can
                         // exceed 10^9+7
    return f;
}

int main()
{
    ll a = 145785635595363569532135132;
    ll b = 3151635135413512165131321321;
    ll c = 999874455222222200651351351;
    int m = 1000000007;
    std::cout << (a * b * c) % m << "\n";
    std::cout << (1 * a) % m << "\n";
    std::cout << ((((a * 1) % m) * b) % m) * c % m << "\n";
    std::cout << ((1 << 41) % A) << "\n";
    std::cout << factorial(64) << "\n";
}