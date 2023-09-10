#include <stdio.h>
#include <algorithm>
#include <cstring>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MIN(a, b) ((a) < (b) ? (a) : (b))

int n;
int h[5005];
int diff[5005];

int main()
{
    memset(diff, 0x3f3f3f3f, sizeof(diff));
    scanf("%d", &n);
    REP(i, 0, n - 1)
    {
        scanf("%d", &h[i]);
    }
    diff[1] = 0;
    int diffVal;
    REP(mid, 0, n - 1)
    {
        diffVal = 0;
        for (int len = 0; mid + len < n && mid - len >= 0; len++)
        {
            diffVal += abs(h[mid + len] - h[mid - len]);
            diff[1 + 2 * len] = MIN(diff[1 + 2 * len], diffVal);
        }
        diffVal = 0;
        for (int len = 0; mid + len + 1 < n && mid - len >= 0; len++)
        {
            diffVal += abs(h[mid + len + 1] - h[mid - len]);
            diff[2 * (len + 1)] = MIN(diff[2 * (len + 1)], diffVal);
        }
    }
    REP(i, 1, n)
    {
        printf("%d ", diff[i]);
    }
}