/*
2 columns, C rows of equilateral tiled triangle
0 is white, 1 is black
find number of triangle sides that border the black
*/

#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

bool t[2][200005];
int b;

int main()
{
    int c;
    scanf("%d", &c);
    REP(i, 0, 2)
    {
        REP(j, 0, c)
        {
            scanf("%d", &t[i][j]);
        }
    }
    REP(i, 0, 2)
    {
        REP(j, 0, c)
        {
            if (t[i][j])
            {
                b += 3;
                if (j + 1 < c && t[i][j + 1])
                {
                    b--;
                }
                if (j - 1 >= 0 && t[i][j - 1])
                {
                    b--;
                }
                if (j % 2 == 0)
                {
                    if (i + 1 < 2 && t[i + 1][j])
                    {
                        b--;
                    }
                    if (i - 1 >= 0 && t[i - 1][j])
                    {
                        b--;
                    }
                }
            }
        }
    }
    printf("%d", b);
}