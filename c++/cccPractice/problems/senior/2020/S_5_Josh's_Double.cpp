#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

int fav[1000005];

int main()
{
    int n;
    scanf("%d", &n);
    REP(i, 0, n)
    {
        scanf("%d", &fav[i]);
    }
}