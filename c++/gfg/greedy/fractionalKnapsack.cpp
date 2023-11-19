#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

typedef pair<int, int> pii;

bool cmp(const pii &a, const pii &b)
{
    return 1.0 * a.second / a.first > 1.0 * b.second / b.first;
}

double getMaxVal(int n, int w, pii *items)
{
    int cap = w;
    double val = 0;
    sort(items, items + n, cmp);
    pii i;
    REP(j, 0, n)
    {
        i = items[j];
        if (i.first <= cap)
        {
            cap -= i.first;
            val += i.second;
        }
        else
        {
            val += (1.0 * i.second / i.first) * cap;
            break;
        }
    }
    return val;
}

int main()
{
    pii items[3] = {{10, 60}, {20, 100}, {30, 120}};
    printf("%.2lf\n", getMaxVal(3, 50, items));
}