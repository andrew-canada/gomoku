#include <stdio.h>
#include <vector>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define INF 150005

int n, m;
int sI, eI, gcd;
int diff[INF][20];
vector<int> st;

int main()
{
    scanf("%d%d", &n, &m);
    REP(i, 0, m - 1)
    {
        scanf("%d%d%d", &sI, &eI, &gcd);
        diff[sI][gcd]++;
        diff[eI + 1][gcd]--;
    }
    REP(i, 0, m - 1)
    {
    }
}