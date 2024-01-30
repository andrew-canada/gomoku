#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef unsigned long long ull;
typedef vector<vector<ull>> mat;

const ull M = 1e9 + 7;

mat mult(mat &a, mat &b)
{
    mat res(a.size(), vector<ull>(b[0].size()));
    for (int i = 0; i < a.size(); i++)
    {
        for (int j = 0; j < b.size(); j++)
        {
            for (int k = 0; k < b[0].size(); k++)
            {
                res[i][j] = (res[i][j] + (a[i][k] * b[k][j]) % M) % M;
            }
        }
    }
    return res;
}

int main()
{
    ull n;
    cin >> n;
    mat ans = {{0, 0, 0, 0, 0, 1}};
    mat b = {
        {0, 0, 0, 0, 0, 1},
        {1, 0, 0, 0, 0, 1},
        {0, 1, 0, 0, 0, 1},
        {0, 0, 1, 0, 0, 1},
        {0, 0, 0, 1, 0, 1},
        {0, 0, 0, 0, 1, 1}};
    while (n)
    {
        if (n & 1)
        {
            ans = mult(ans, b);
        }
        b = mult(b, b);
        n >>= 1;
    }
    cout << ans[0][5];
}