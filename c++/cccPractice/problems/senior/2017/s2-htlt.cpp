#include <stdio.h>
#include <vector>
#include <algorithm>

#define REP(i, a, b) for (int i = int(a); i <= int(b - 1); i++)

using namespace std;

int n;
int half;

int main()
{
    scanf("%d", &n);
    vector<int> m(n);
    REP(i, 0, n)
    {
        scanf("%d", &m[i]);
    }
    sort(m.begin(), m.end());
    half = n / 2;
    if (n % 2 == 0)
    {
        REP(i, 0, half)
        {
            printf("%d %d ", m[half - i - 1], m[half + i]);
        }
    }
    else
    {
        REP(i, 0, half)
        {
            printf("%d %d ", m[half - i], m[half + i + 1]);
        }
        printf("%d", m[0]);
    }
}