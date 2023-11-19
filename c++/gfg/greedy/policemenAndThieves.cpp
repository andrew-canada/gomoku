#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

int getMaxThieves(char *arr, int n, int k)
{
    int mt = 0;
    vector<int> p, t;
    REP(i, 0, n)
    {
        if (arr[i] == 'P')
        {
            p.push_back(i);
        }
        else
        {
            t.push_back(i);
        }
    }
    int pIdx = 0, tIdx = 0;
    while (pIdx < p.size() && tIdx < t.size())
    {
        if (abs(p[pIdx] - t[tIdx]) <= k)
        {
            mt++;
            pIdx++;
            tIdx++;
        }
        else if (p[pIdx] < t[tIdx])
        {
            pIdx++;
        }
        else
        {
            tIdx++;
        }
    }

    return mt;
}

int main()
{
    char arr[10] = {'T', 'P', 'P', 'P', 'P', 'T', 'T', 'T', 'T', 'P'};
    printf("%d\n", getMaxThieves(arr, 10, 3));
}