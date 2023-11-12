#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

typedef long long ll;

int t, n;
char arr[100005];
int psa[100005];
ll num;
unordered_map<int, int> sum;

int main()
{
    scanf("%d", &t);
    REP(i, 1, t)
    {
        num = 0;
        scanf("%d", &n);
        scanf("%s", &arr);
        psa[0] = 0;
        REP(j, 1, n)
        {
            psa[j] = psa[j - 1] + arr[j - 1] - '0';
        }
        REP(j, 0, n)
        {
            sum[psa[j] - j]++;
        }
        for (const auto &j : sum)
        {
            num += (ll)j.second * (j.second - 1) / 2;
        }
        printf("%lld\n", num);
        sum.clear();
    }
}