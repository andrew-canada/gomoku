#include <bits/stdc++.h>

using namespace std;

string s[8];
int pos[8];
bool isQueen[15];

int main()
{
    freopen("1624.out", "w", stdout);
    for (int i = 0; i < 8; i++)
    {
        cin >> s[i];
    }
    int ans = 0;
    iota(pos, pos + 8, 0);
    do
    {
        // for (int i : pos)
        // {
        //     cout << i << " ";
        // }
        // cout << '\n';
        bool canPlace = true;
        for (int i = 0; i < 8; i++)
        {
            canPlace &= s[i][pos[i]] == '.';
        }
        memset(isQueen, 0, 15);
        for (int i = 0; i < 8; i++)
        {
            if (isQueen[i + pos[i]])
            {
                canPlace = false;
            }
            isQueen[i + pos[i]] = true;
        }
        memset(isQueen, 0, 15);
        for (int i = 0; i < 8; i++)
        {
            if (isQueen[i + 7 - pos[i]])
            {
                canPlace = false;
            }
            isQueen[i + 7 - pos[i]] = true;
        }
        ans += canPlace;
    } while (next_permutation(pos, pos + 8));
    cout << ans;
}