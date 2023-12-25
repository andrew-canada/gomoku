/*
n integers
m requirements
gcd from term a to term b, inclusive, is equal to z
gcd = largest integer such that all terms are divisible by it
find a sequence or print Impossible if not possible
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define pb push_back
#define INF 0x3f3f3f3f

int seq[2005];
int idx1[2005], idx2[2005], val[2005];

int main()
{
    int n, m;
    scanf("%d%d", &n, &m);
    fill(seq, seq + n + 1, 1);
    REP(i, 1, m)
    {
        scanf("%d%d%d", &idx1[i], &idx2[i], &val[i]);
        if (val[i] == 2)
        {
            REP(j, idx1[i], idx2[i])
            {
                seq[j] = 2;
            }
        }
    }
    REP(i, 1, m)
    {
        REP(j, idx1[i], idx2[i])
        {
            if (seq[j] != val[i])
            {
                printf("Impossible");
                return 0;
            }
        }
    }
    REP(i, 1, n)
    {
        printf("%d ", seq[i]);
    }
}