#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

typedef vector<int> vi;

using namespace std;

int iCube[3][3];
vi rows[3];
vi cols[3];
int numX;

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
                iCube[i][j] = 1000001;
                rows[i].append(j);
                cols[j].append(i);
                numX++;
            }
            else
            {
                iCube[i][j] = stoi(s);
            }
        }
    }
    while (numX > 0)
    {
        REP(i, 0, 3)
        {
            if (rows[i].size() > 0)
            {
            }
        }
    }
    REP(i, 0, 3)
    {
        REP(j, 0, 3)
        {
            cout << iCube[i][j] << " ";
        }
        cout << "\n";
    }
}