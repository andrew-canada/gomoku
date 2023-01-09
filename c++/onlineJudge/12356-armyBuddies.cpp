#include <stdio.h>

// #define LOCAL

bool ln[100005];

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    int ls, c;
    int l, r;
    bool lf = false, rf = false;

    while (scanf("%d %d", &ls, &c) && ls != 0 && c != 0)
    {
        for (int i = 1; i <= ls; i++)
        {
            ln[i] = true;
        }
        for (int i = 1; i <= c; i++)
        {
            scanf("%d %d", &l, &r);
            for (int j = l; j <= r; j++)
            {
                ln[j] = false;
            }
            for (int lr = l - 1; lr > 0; lr--)
            {
                if (ln[lr])
                {
                    lf = true;
                    printf("%d ", lr);
                    break;
                }
            }
            if (!lf)
            {
                printf("%s ", "*");
            }
            for (int rr = r + 1; rr <= ls; rr++)
            {
                if (ln[rr])
                {
                    rf = true;
                    printf("%d\n", rr);
                    break;
                }
            }
            if (!rf)
            {
                printf("%s\n", "*");
            }
            lf = false;
            rf = false;
        }
        for (int i = 1; i <= ls; i++)
        {
            ln[i] = false;
        }
        printf("%s\n", "-");
    }
    return 0;
}