#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

int cv;
int r[2000005];
vector<pii> freq;

int main()
{
    int n;
    int val;
    scanf("%d", &n);
    REP(i, 0, n)
    {
        scanf("%d", &r[i]);
    }
    sort(r, r + n);
    REP(i, 0, n)
    {
        if (cv == r[i])
        {
            freq.back().first++;
        }
        else
        {
            freq.push_back({1, r[i]});
            cv = r[i];
        }
    }
    sort(freq.begin(), freq.end(), greater<pii>());
    int occ = freq[0].first;
    int i = 1;
    for (i; i < 1005; i++)
    {
        if (freq[i].first != occ)
        {
            occ = freq[i].first;
            break;
        }
    }
    if (i != 1)
    {
        printf("%d", freq[0].second - freq[i - 1].second);
        return 0;
    }
    if (i == n)
    {
        printf("%d", freq[0].second - freq[n - 1].second);
        return 0;
    }
    int val1 = freq[i].second - freq[i - 1].second;
    for (i; i < 1005; i++)
    {
        if (freq[i].first != occ)
        {
            printf("%d", max(val1, freq[0].second - freq[i - 1].second));
            return 0;
        }
    }
}