#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

int n;
char ans[10005];
char c;
int cor;

int main()
{
    scanf("%d", &n);
    REP(i, 0, n)
    {
        scanf(" %c", &ans[i]);
    }
    REP(i, 0, n)
    {
        scanf(" %c", &c);
        if (ans[i] == c)
        {
            cor++;
        }
    }
    printf("%d", cor);
}