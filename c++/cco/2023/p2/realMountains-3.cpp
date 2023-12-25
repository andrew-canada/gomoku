// n columns of pixels of height Hn
// peak is higher than left and right
// result only has one peak
// (i, j, k) -> peak j increments for cost Hi+Hj+Hk
// minimize cost to create single peak

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define INF 0x3f3f3f3f
#define pb push_back

const int MAXN = 1000005;
int finalHeight[MAXN];
int currentHeight[MAXN];
pii minPos[MAXN];
int cost;
int minVal;
int maxVal = -1;
int maxIdx;

int main()
{
    int n;
    scanf("%d", &n);
    REP(i, 1, n)
    {
        scanf("%d", &currentHeight[i]);
        minPos[i] = {currentHeight[i], i};
    }
    REP(i, 1, maxIdx - 1)
    {
        finalHeight[i] = max(finalHeight[i - 1], currentHeight[i]);
    }
    for (int i = n; i > maxIdx; i--)
    {
        finalHeight[i] = max(finalHeight[i + 1], currentHeight[i]);
    }
    sort(minPos + 1, minPos + 1 + n);
    int first, last;
    int curH, curIdx;
    REP(i, 1, n)
    {
        curH = minPos[i].first, curIdx = minPos[i].second;
        // if (minPos[i].first < currentHeight[])
    }

    printf("%d", cost);
}