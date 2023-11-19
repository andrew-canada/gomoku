// C++ program for nCr Mod  p forLarge Prime
#include <bits/stdc++.h>
using namespace std;

#define ll long long
const int maxn = 1000005, p = 1e6 + 3;
ll fact[maxn], invf[maxn];

class GFG
{
public:
    // Iterative Function to calculate (x^y)%p in O(log y)
    long long p;
    unsigned long long power(unsigned long long x, int y, int p)
    {
        unsigned long long res = 1; // Initialize result

        x = x % p; // Update x if it is more than or
        // equal to p

        while (y > 0)
        {

            // If y is odd, multiply x with result
            if (y & 1)
                res = (res * x) % p;

            // y must be even now
            y = y >> 1; // y = y/2
            x = (x * x) % p;
        }
        return res;
    }

    // Returns n^(-1) mod p
    unsigned long long modInv(unsigned long long n, int p)
    {
        return power(n, p - 2, p);
    }
    void premcompute()
    {
        fact[0] = 1;
        fact[1] = 1;
        invf[0] = 1;
        invf[1] = 1;

        for (int i = 2; i < maxn; i++)
        {
            fact[i] = (fact[i - 1] * i) % p;
            invf[i] = modInv(fact[i], p);
        }
    }
    ll query(int n, int r)
    {
        return ((fact[n] * invf[r] % p) * invf[n - r]) % p;
    }
};

// Driver program
int main()
{
    // p must be a prime greater than n.
    int n = 1000000, r = 500000, p = 1e6 + 3;
    class GFG obj;
    obj.p = p;
    obj.premcompute();
    cout << "Value of nCr % p is " << obj.query(n, r);
    return 0;
}
