#include <stdio.h>
#include <string>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
#define INF 0x3f3f3f3f

int square[3][3];
int xr[3], xc[3];
int nx;

int main()
{
    char val[7];
    REP(i, 0, 3)
    {
        REP(j, 0, 3)
        {
            scanf("%s", &val);
            string s(val);
            if (val[0] == 'X')
            {
                square[i][j] = INF;
                nx++;
                xr[i]++;
                xc[j]++;
            }
            else
            {
                square[i][j] = stoi(val);
            }
        }
    }
    while (nx > 0)
    {
        REP(i, 0, 3)
        {
            if (xr[i] == 1)
            {
                xr[i]--;
                nx--;
                if (square[i][0] == INF)
                {
                    square[i][0] = square[i][1] - (square[i][2] - square[i][1]);
                    xc[0]--;
                }
                else if (square[i][1] == INF)
                {
                    square[i][1] = (square[i][0] - square[i][2]) / 2;
                    xc[1]--;
                }
                else
                {
                    square[i][2] = square[i][1] + (square[i][1] - square[i][0]);
                    xc[2]--;
                }
            }
            if (xc[i] == 1)
            {
                xc[i]--;
                nx--;
                if (square[0][i] == INF)
                {
                    square[0][i] = square[0][i] - (square[2][i] - square[1][i]);
                    xr[0]--;
                }
                else if (square[1][i] == INF)
                {
                    square[1][i] = (square[0][i] - square[2][i]) / 2;
                    xr[1]--;
                }
                else
                {
                    square[2][i] = square[1][i] + (square[1][i] - square[0][i]);
                    xr[2]--;
                }
            }
        }
        if (square[1][1] == INF)
        {
            square[1][1] = 0;
            nx--;
            xr[1]--;
            xc[1]--;
            continue;
        }
        if (square[0][1] == INF)
        {
            square[0][1] = 0;
            nx--;
            xr[0]--;
            xc[1]--;
            continue;
        }
        if (square[2][1] == INF)
        {
            square[2][1] = 0;
            nx--;
            xr[2]--;
            xc[1]--;
            continue;
        }
        if (square[1][0] == INF)
        {
            square[1][0] = 0;
            nx--;
            xr[1]--;
            xc[0]--;
            continue;
        }
        if (square[1][2] == INF)
        {
            square[1][2] = 0;
            nx--;
            xr[1]--;
            xc[2]--;
            continue;
        }
        if (square[0][0] == INF)
        {
            square[0][0] = 0;
            nx--;
            xr[0]--;
            xc[0]--;
            continue;
        }
    }
    REP(i, 0, 3)
    {
        REP(j, 0, 3)
        {
            printf("%d ", square[i][j]);
        }
        printf("\n");
    }
}