#include <stdio.h>
#include <algorithm>
#include <cstring>

// #define LOCAL
#define REP(i, a, b) for (int i = int(a); i <= int(b - 1); i++)

int n;
int v1, v2;
int diff;
bool seq[3005];

int main()
{
#ifdef LOCAL
    freopen("10038.in", "r", stdin);
#endif
    while (scanf("%d", &n) != EOF)
    {

        scanf("%d", &v1);
        REP(i, 0, n - 1)
        {
            scanf("%d", &v2);
            diff = std::abs(v1 - v2);
            if (diff < n)
            {
                seq[diff] = true;
            }
            v1 = v2;
        }
        if (n == 1)
        {
            puts("Jolly");
            continue;
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
    }
}