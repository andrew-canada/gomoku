#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define INF 0x3f3f3f3f

const int mxN = 1e6;

int main()
{
    int steps = 0;
    int n;
    scanf("%d", &n);
    while (n > 0)
    {
        int maxDig = -1;
        for (char c : to_string(n))
        {
            maxDig = max(maxDig, c - '0');
        }
        n -= maxDig;
        steps++;
    }
    printf("%d\n", steps);
}