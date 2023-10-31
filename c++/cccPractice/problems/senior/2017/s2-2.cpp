#include <stdio.h>
#include <cstring>
#include <algorithm>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

int n;
int tides[100];

int main()
{
    scanf("%d", &n);
    REP(i, 0, n)
    {
        scanf("%d", &tides[i]);
    }
    sort(tides, tides + n);
    int mid = (n - 1) / 2;
    printf("%d ", tides[mid]);
    int nv = 1;
    REP(i, 1, mid + 1)
    {
        printf("%d %d ", tides[mid + i], tides[mid - i]);
        nv += 2;
    }
    if (nv != n)
    {
        printf("%d", tides[n - 1]);
    }
}