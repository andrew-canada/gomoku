/*
g groups of 3 names
x pairs of names must be in same group
y pairs of names must be in different group
number of letters in name: [1, 10]
*/

#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

char n1[15], n2[15], n3[15];
string s1[100005], s2[100005], d1[100005], d2[100005];
unordered_map<string, int> groups;
int nr;

int main()
{
    int x, y, g;
    scanf("%d", &x);
    REP(i, 0, x)
    {
        scanf("%s%s", n1, n2);
        s1[i] = n1, s2[i] = n2;
    }
    scanf("%d", &y);
    REP(i, 0, y)
    {
        scanf("%s%s", n1, n2);
        d1[i] = n1, d2[i] = n2;
    }
    scanf("%d", &g);
    REP(i, 0, g)
    {
        scanf("%s%s%s", n1, n2, n3);
        groups[n1] = groups[n2] = groups[n3] = i;
    }

    REP(i, 0, x)
    {
        if (groups[s1[i]] != groups[s2[i]])
        {
            nr++;
        }
    }
    REP(i, 0, y)
    {
        if (groups[d1[i]] == groups[d2[i]])
        {
            nr++;
        }
    }
    printf("%d", nr);
}