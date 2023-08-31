#include <stdio.h>
#include <vector>
#include <numeric>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define INF 150005

int n, m;
int sI, eI, gcdVal;
int val[INF];
int ans;
vector<int> st;

int main()
{
    scanf("%d%d", &n, &m);
    REP(i, 1, m)
    {
        scanf("%d%d%d", &sI, &eI, &gcdVal);
        val[sI] = (val[sI] ? val[sI] * gcdVal : gcdVal);
        val[eI] = (val[eI] ? val[eI] * gcdVal : gcdVal);
    }
    REP(i, 1, n)
    {
        printf("%d ", val[i]);
    }
}