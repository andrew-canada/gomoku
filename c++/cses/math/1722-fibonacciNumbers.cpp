#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef unsigned long long ull;
typedef vector<vector<ull>> mat;

const ull M = 1e9 + 7;
const ull M2 = M * M;

mat mult(mat &a, mat &b)
{
    mat res = {{0, 0}, {0, 0}};
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                res[i][j] = (res[i][j] + (a[i][k] * b[k][j]) % M) % M;
                // res[i][j] += a[i][k] * b[k][j];
                // if (res[i][j] >= M2)
                // {
                //     res[i][j] -= M2;
                // }
                // res[i][j] %= M;
            }
        }
    }
    return res;
}

int main()
{
    ull n;
    cin >> n;

    mat ans = {{1, 1}, {1, 0}};
    mat b = {{1, 1}, {1, 0}};
    while (n)
    {
        if (n & 1)
        {
            ans = mult(ans, b);
        }
        b = mult(b, b);
        n >>= 1;
    }
    cout << ans[1][1];
}