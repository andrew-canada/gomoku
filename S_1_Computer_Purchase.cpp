// n computers
// each has string name; int r, s, d
// rank computers using 2r+3s+d (decreasing) and name (increasing)
// print top two computers (only one computer if n=1)

#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

struct comp
{
    string name;
    int v;
    bool operator<(const comp &c)
    {
        return v == c.v ? name < c.name : v > c.v;
    }
};

char nm[25];
comp computer[10005];

int main()
{
    int n;
    int r, s, d;
    scanf("%d", &n);
    REP(i, 0, n)
    {
        scanf("%s%d%d%d", &nm, &r, &s, &d);
        computer[i].name = nm;
        computer[i].v = 2 * r + 3 * s + d;
    }
    sort(computer, computer + n);
    if (computer[0].v)
    {
        for (char c : computer[0].name)
        {
            printf("%c", c);
        }
        printf("\n");
    }
    if (computer[1].v)
    {
        for (char c : computer[1].name)
        {
            printf("%c", c);
        }
        printf("\n");
    }
}