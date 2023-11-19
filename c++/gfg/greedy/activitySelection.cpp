#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

typedef pair<int, int> pii;

bool cmp(const pii &a, const pii &b)
{
    return a.second < b.second;
}

int getMaxActivities(pii *arr, int n)
{
    int act = 1;
    sort(arr, arr + n, cmp);
    pii cur = arr[0];
    REP(i, 1, n)
    {
        if (arr[i].first >= cur.second)
        {
            act++;
            cur = arr[i];
        }
    }
    return act;
}

int main()
{
    pii arr[3] = {{12, 25}, {10, 20}, {20, 30}};
    printf("%d\n", getMaxActivities(arr, 3));
}