#include <stdio.h>
#include <iostream>
#include <string>

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

using namespace std;

int sqr[3][3];
int xinr[3];
int xinc[3];
int numX;
const int inf = 1000001;

int main()
{
    ios_base::sync_with_stdio(false);
    REP(i, 0, 3)
    {
        REP(j, 0, 3)
        {
            string s;
            cin >> s;
            if (s == "X")
            {
                sqr[i][j] = inf;
                xinr[i]++;
                xinc[j]++;
                numX++;
            }
            else
            {
                sqr[i][j] = stoi(s);
            }
        }
    }
    while (numX > 0)
    {
        bool changed = false;
        REP(i, 0, 3)
        {
            if (xinr[i] == 1)
            {
                numX--;
                xinr[i]--;
                if (sqr[i][0] == inf)
                {
                    sqr[i][0] = sqr[i][1] - (sqr[i][2] - sqr[i][1]);
                    xinc[0]--;
                }
                else if (sqr[i][1] == inf)
                {
                    sqr[i][1] = (sqr[i][0] + sqr[i][2]) / 2;
                    xinc[1]--;
                }
                else if (sqr[i][2] == inf)
                {
                    sqr[i][2] = sqr[i][1] + (sqr[i][1] - sqr[i][0]);
                    xinc[2]--;
                }
                changed = true;
                break;
            }
            if (xinc[i] == 1)
            {
                numX--;
                xinc[i]--;
                if (sqr[0][i] == inf)
                {
                    sqr[0][i] = sqr[1][i] - (sqr[2][i] - sqr[1][i]);
                    xinr[0]--;
                }
                else if (sqr[1][i] == inf)
                {
                    sqr[1][i] = (sqr[0][i] + sqr[2][i]) / 2;
                    xinr[1]--;
                }
                else if (sqr[2][i] == inf)
                {
                    sqr[2][i] = sqr[1][i] + (sqr[1][i] - sqr[0][i]);
                    xinr[2]--;
                }
                changed = true;
                break;
            }
        }
        if (changed)
        {
            continue;
        }
        if (sqr[1][1] == inf)
        {
            sqr[1][1] = 0;
            xinr[1]--;
            xinc[1]--;
            numX--;
            continue;
        }
        if (sqr[0][1] == inf)
        {
            sqr[0][1] = 0;
            xinr[0]--;
            xinc[1]--;
            numX--;
            continue;
        }
        if (sqr[2][1] == inf)
        {
            sqr[2][1] = 0;
            xinr[2]--;
            xinc[1]--;
            numX--;
            continue;
        }
        if (sqr[1][0] == inf)
        {
            sqr[1][0] = 0;
            xinr[1]--;
            xinc[0]--;
            numX--;
            continue;
        }
        if (sqr[1][2] == inf)
        {
            sqr[1][2] = 0;
            xinr[1]--;
            xinc[2]--;
            numX--;
            continue;
        }
        if (sqr[0][0] == inf)
        {
            sqr[0][0] = 0;
            xinr[0]--;
            xinc[0]--;
            numX--;
            continue;
        }
    }
    REP(i, 0, 3)
    {
        REP(j, 0, 3)
        {
            cout << sqr[i][j] << " ";
        }
        cout << "\n";
    }
}