/*
use difference array for efficient range update queries
add when entering the range, subtract when leaving
2d diff array: think of rectangles
    1. add top left (add area starting at top left)
    2. subtract top right and bottom left (subtract area outside of range)
    3. add bottom right (because this area is subtracted twice in step 2)
to calculate net change: add left, add up, subtract diagonal upper left
*/

#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define pb push_back

typedef long long ll;

const int mxN = 100;

int diff[mxN + 1][mxN + 1];

int main()
{
    int n, t;
    cin >> n >> t;
    for (int i = 0, tx, ty, bx, by; i < n; i++)
    {
        cin >> tx >> ty >> bx >> by;
        diff[tx][ty]++, diff[bx][by]++, diff[tx][by]--, diff[bx][ty]--;
    }
    int ans = 0;
    for (int i = 1; i < 5; i++)
    {
        for (int j = 1; j < 5; j++)
        {
            diff[i][j] = diff[i][j] + diff[i][j - 1] + diff[i - 1][j] - diff[i - 1][j - 1];
            if (diff[i][j] >= t)
            {
                ans++;
            }
        }
    }
    cout << ans;
}

/*
2 2
1 1 2 4
1 3 4 4
*/