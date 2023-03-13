#include <stdio.h>
#include <vector>
#include <string>
#include <utility>
#include <algorithm>

using namespace std;

// #define LOCAL

typedef pair<string, int> psi;

char nameArr[20];
int n;
int r, s, d;

bool sortValName(psi c1, psi c2)
{
    if (c2.second == c1.second)
    {
        return c2.first > c1.first;
    }
    else
    {
        return c2.second < c1.second;
    }
}

int main()
{
#ifdef LOCAL
    freopen("s1.in", "r", stdin);
#endif
    scanf("%d", &n);
    vector<psi> vals(n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s %d %d %d", &nameArr, &r, &s, &d);
        string name(nameArr);
        vals[i].first = name;
        vals[i].second = 2 * r + 3 * s + d;
    }

    if (n < 2)
    {
        if (n == 1)
        {
            printf("%s", vals[0].first.c_str());
        }
        return 0;
    }

    sort(vals.begin(), vals.end(), sortValName);

    printf("%s\n%s", vals[0].first.c_str(), vals[1].first.c_str());
}