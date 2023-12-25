/*
n column; column i has height h(i)
define crop as contiguous columns from l to r
define diff as sum of difference between h(l) and h(r), moving out from center of crop
output n number, n(i) is min difference of crop of length n (start from 1)
*/

#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define INF 0x3f3f3f3f

int h[100005];

int main()
{
    int n;
    scanf("%d", &n);
    REP(i, 0, n - 1)
    {
        scanf("%d", &h[i]);
    }
    printf("0 ");
    int len1, l1;
    int val;
    int mv;
    REP(len, 2, n)
    {
        mv = INF;
        REP(l, 0, n - len)
        {
            val = 0;
            len1 = len;
            l1 = l;
            while (len1 > 1)
            {
                val += abs(h[l1] - h[l1 + len1 - 1]);
                len1 -= 2;
                l1++;
            }
            if (val > mv)
            {
                continue;
            }
            mv = min(mv, val);
        }
        printf("%d ", mv);
    }
}