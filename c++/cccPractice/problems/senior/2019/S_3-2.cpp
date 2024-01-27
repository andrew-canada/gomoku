#include <bits/stdc++.h>

using namespace std;

#define INF 0xf3f3f3f

int grid[3][3];
int xr[3], xc[3];

int main()
{
    string s;
    int nx = 0;
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> s;
            if (s == "X")
            {
                grid[i][j] = INF;
                nx++;
                xr[i]++, xc[j]++;
            }
            else
            {
                grid[i][j] = stoi(s);
            }
        }
    }
    while (nx)
    {
        // calculate common difference to get missing term
        bool need = true;
        for (int i = 0; i < 3; i++)
        {
            if (xr[i] == 1)
            {
                nx--;
                need = false;
                if (grid[i][0] == INF)
                {
                    grid[i][0] = grid[i][1] - (grid[i][2] - grid[i][1]);
                    xr[i]--, xc[0]--;
                }
                else if (grid[i][1] == INF)
                {
                    grid[i][1] = (grid[i][0] + grid[i][2]) / 2;
                    xr[i]--, xc[1]--;
                }
                else
                {
                    grid[i][2] = grid[i][1] + (grid[i][1] - grid[i][0]);
                    xr[i]--, xc[2]--;
                }
            }
            if (xc[i] == 1)
            {
                nx--;
                need = false;
                if (grid[0][i] == INF)
                {
                    grid[0][i] = grid[1][i] - (grid[2][i] - grid[1][i]);
                    xr[0]--, xc[i]--;
                }
                else if (grid[1][i] == INF)
                {
                    grid[1][i] = (grid[0][i] + grid[2][i]) / 2;
                    xr[1]--, xc[i]--;
                }
                else
                {
                    grid[2][i] = grid[1][i] + (grid[1][i] - grid[0][i]);
                    xr[2]--, xc[i]--;
                }
            }
        }
        // filler
        if (!need)
        {
            continue;
        }
        if (grid[1][1] == INF)
        {
            grid[1][1] = 0;
            xr[1]--, xc[1]--;
            nx--;
            continue;
        }
        if (grid[0][1] == INF)
        {
            grid[0][1] = 0;
            xr[0]--, xc[1]--;
            nx--;
            continue;
        }
        if (grid[2][1] == INF)
        {
            grid[2][1] = 0;
            xr[2]--, xc[1]--;
            nx--;
            continue;
        }
        if (grid[1][0] == INF)
        {
            grid[1][0] = 0;
            xr[1]--, xc[0]--;
            nx--;
            continue;
        }
        if (grid[1][2] == INF)
        {
            grid[1][2] = 0;
            xr[1]--, xc[2]--;
            nx--;
            continue;
        }
        if (grid[0][0] == INF)
        {
            grid[0][0] = 0;
            xr[0]--, xc[0]--;
            nx--;
            continue;
        }
    }
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cout << grid[i][j] << " ";
        }
        cout << '\n';
    }
}