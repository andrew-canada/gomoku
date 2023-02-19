#include <stdio.h>
#include <bitset>

using namespace std;

int c;
bool rows[2][200001];
int tot;
int n;

int main()
{
    scanf("%d", &c);
    for (int i = 0; i < c; i++)
    {
        scanf("%d", &n);
        if (n)
        {
            tot += 3;
        }
        rows[0][i] = n;
    }
    for (int i = 0; i < c; i++)
    {
        scanf("%d", &n);
        if (n)
        {
            tot += 3;
        }
        rows[1][i] = n;
    }

    for (int i = 0; i < c - 1; i++)
    {
        int u = rows[0][i];
        int l = rows[1][i];
        if (u && rows[0][i + 1])
        {
            tot -= 2;
        }
        if (l && rows[1][i + 1])
        {
            tot -= 2;
        }
        if ((i % 2 == 0) && (u && l))
        {
            tot -= 2;
        }
    }

    if (((c - 1) % 2 == 0) && (rows[0][c - 1] && rows[1][c - 1]))
    {
        tot -= 2;
    }

    printf("%d", tot);
}