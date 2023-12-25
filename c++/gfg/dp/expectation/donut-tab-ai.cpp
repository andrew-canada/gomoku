#include <bits/stdc++.h>

using namespace std;

double donut(int n, int three, int two, int one);

double dp[100][100][100];

int main()
{
    int n = 3;
    // int arr[3] = {1, 1, 1};
    printf("hello\n");
    donut(n, 0, 0, 3);
    printf("ahello\n");
    printf("%lf\n", donut(n, 0, 0, 3));
}

double donut(int n, int three, int two, int one)
{
    printf("abc\n");
    memset(dp, 0, sizeof(dp));

    for (int i = 0; i <= three; i++)
    {
        for (int j = 0; j <= two; j++)
        {
            for (int k = 0; k <= one; k++)
            {
                if (i == 0 && j == 0 && k == 0)
                {
                    dp[i][j][k] = 0;
                }
                else
                {
                    double e = 0;
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
    }
    printf("a%lf\n", dp[three][two][one]);
    return dp[three][two][one];
}