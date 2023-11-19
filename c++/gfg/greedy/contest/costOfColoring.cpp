#include <bits/stdc++.h>
using namespace std;

int vals[100005];
int cols[100005];

int main()
{
    int t, n;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &vals[i]);
        }
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &cols[i]);
        }
        sort(vals, vals + n);
        sort(cols, cols + n);
        int col = 0;
        int cost = cols[0];
        for (int i = 1; i < n; i++)
        {
            if (vals[i] == vals[i - 1])
            {
                cost += cols[col + 1];
                col++;
            }
            else
            {
                col = 0;
                cost += cols[col];
            }
            // printf("|%d %d\n", i, cost);
        }
        printf("%d\n", cost);
    }
    return 0;
}

/*
2
6
1 1 1 2 3 4
5 2 4 2 6 3
1
1
5
*/