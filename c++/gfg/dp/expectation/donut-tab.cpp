#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

double et(int n, int three, int two, int one);

double dp[100][100][100];

int main()
{
    int n = 3;
    // int arr[3] = {1, 1, 1};
    printf("%lf\n", et(n, 0, 0, 3));
}

double et(int n, int three, int two, int one)
{
    double e;
    REP(i, 0, three)
    {
        REP(j, 0, two)
        {
            REP(k, 0, one)
            {
                if (i == 0 && j == 0 && k == 0)
                {
                    continue;
                }
                e = (double)(n - i - j - k) / n;
                if (i > 0)
                {
                    e += (double)i / n * (1 + dp[i - 1][j + 1][k]);
                }
                if (j > 0)
                {
                    e += (double)j / n * (1 + dp[i][j - 1][k + 1]);
                }
                if (k > 0)
                {
                    e += (double)k / n * (1 + dp[i][j][k - 1]);
                }
                e /= 1 - (double)(n - i - j - k) / n;
                dp[i][j][k] = e;
            }
        }
    }
    return dp[three][two][one];
}