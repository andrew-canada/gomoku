// find number of ways to write a number as sum of 4s and 5s
// order does not matter

#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

int main()
{
    int n;
    scanf("%d", &n);
    int nw = 0;
    while (n >= 0)
    {
        if (n % 4 == 0)
        {
            nw++;
        }
        n -= 5;
    }
    printf("%d", nw);
}