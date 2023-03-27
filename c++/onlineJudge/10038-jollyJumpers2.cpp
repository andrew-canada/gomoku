#include <stdio.h>
#include <algorithm>
#include <cstring>

// #define LOCAL
#define REP(i, a, b) for (int i = int(a); i <= int(b - 1); i++)

int n;
int diff;
int vals[3005];
bool seq[3005];

int main()
{
#ifdef LOCAL
    freopen("10038.in", "r", stdin);
    freopen("10038.out", "w", stdout);
#endif
    while (scanf("%d", &n) != EOF)
    {
        REP(i, 0, n)
        {
            scanf("%d", &vals[i]);
        }

        if (n == 1)
        {
            puts("Jolly");
            continue;
        }

        REP(i, 0, n - 1)
        {
            diff = std::abs(vals[i] - vals[i + 1]);
            if (diff < n)
            {
                seq[diff] = true;
            }
        }
        bool jolly = true;
        REP(i, 1, n)
        {
            if (seq[i] == false)
            {
                puts("Not jolly");
                jolly = false;
                break;
            }
        }
        if (jolly)
        {
            puts("Jolly");
        }

        memset(seq, 0, sizeof(seq));
        memset(vals, 0, sizeof(vals));
    }
}