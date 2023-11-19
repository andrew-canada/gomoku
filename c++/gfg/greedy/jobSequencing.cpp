#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

typedef pair<int, int> pii;

struct job
{
    int dl, p;
};

bool cmp(const job &a, const job &b)
{
    if (a.p == b.p)
    {
        return a.dl > b.dl;
    }
    return a.p > b.p;
}

pii jobSeq(job *arr, int n, int mdl)
{
    int nj = 0, tp = 0;
    sort(arr, arr + n, cmp);
    set<int> ts;
    REP(i, 1, mdl)
    {
        ts.insert(-i);
    }
    REP(i, 0, n - 1)
    {
        auto it = ts.lower_bound(-arr[i].dl);
        if (it != ts.end())
        {
            nj++;
            tp += arr[i].p;
            ts.erase(it);
        }
    }

    return {nj, tp};
}

int main()
{
    int n = 4;
    int mdl = 4;
    job arr[4] = {{4, 20}, {1, 10}, {1, 40}, {1, 30}};
    pii ans = jobSeq(arr, n, mdl);
    printf("%d %d\n", ans.first, ans.second);

    n = 2;
    mdl = 2;
    job arr1[2] = {{1, 10}, {2, 8}};
    ans = jobSeq(arr1, n, mdl);
    printf("%d %d\n", ans.first, ans.second);

    n = 7;
    mdl = 4;
    job arr2[7] = {{4, 20}, {3, 50}, {4, 50}, {1, 10}, {1, 40}, {1, 50}, {1, 30}};
    ans = jobSeq(arr2, n, mdl);
    printf("%d %d\n", ans.first, ans.second);
}