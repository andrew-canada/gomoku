#include <stdio.h>

// #define LOCAL

struct Soldier
{
    int left;
    int right;
};

Soldier ln[100005];

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    int ls, c;
    int l, r;

    while (scanf("%d %d", &ls, &c) && ls != 0 && c != 0)
    {
        for (int i = 1; i <= ls; i++)
        {
            ln[i].left = i - 1;
            ln[i].right = i + 1;
        }
        for (int i = 1; i <= c; i++)
        {
            scanf("%d %d", &l, &r);
            if (ln[l].left >= 1)
            {
                printf("%d ", ln[l].left);
            }
            else
            {
                printf("* ");
            }
            if (ln[r].right <= ls)
            {
                printf("%d\n", ln[r].right);
            }
            else
            {
                printf("*\n");
            }
            ln[ln[l].left].right = ln[r].right;
            ln[ln[r].right].left = ln[l].left;
        }
        printf("%s\n", "-");
    }
    return 0;
}
