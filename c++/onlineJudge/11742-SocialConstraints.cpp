#include <stdio.h>
#include <algorithm>
#include <cstdlib>

// #define LOCAL

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    freopen("out.txt", "w", stdout);
#endif
    int n, m;

    while (scanf("%d %d", &n, &m), n || m)
    {
        int i1, i2;
        int a[20], b[20], c[20];
        int seats[8];
        int nSol = 0;
        for (int i = 0; i < n; i++)
        {
            seats[i] = i;
        }
        for (int i = 0; i < m; i++)
        {
            scanf("%d %d %d", &a[i], &b[i], &c[i]);
        }

        do
        {
            bool allOk = true;
            int numPass = 0;
            for (int i = 0; i < m && allOk; i++)
            {
                i1 = seats[a[i]];
                i2 = seats[b[i]];

                int d = std::abs(i2 - i1);
                if (c[i] > 0)
                {
                    allOk = (d <= c[i]);
                }
                else
                {
                    allOk = (d >= -c[i]);
                }
            }
            if (allOk)
            {
                nSol += 1;
            }
        } while (std::next_permutation(seats, seats + n));
        printf("%d\n", nSol);
    }
}