#include <stdio.h>
#include <string>
#include <map>

using namespace std;

// no space between function name and opening parameter bracket
#define REP(i, a, b) for (int i = int(a); i <= int(b - 1); i++)

int t, s, g;
char n1[15];
char n2[15];
char n3[15];
string t1[100005], t2[100005], s1[100005], s2[100005];
map<string, int> groups;
int v;

int main()
{
    scanf("%d", &t);
    REP(i, 0, t)
    {
        scanf("%s %s", &n1, &n2);
        t1[i] = n1;
        t2[i] = n2;
    }
    scanf("%d", &s);
    REP(i, 0, s)
    {
        scanf("%s %s", &n1, &n2);
        s1[i] = n1;
        s2[i] = n2;
    }
    scanf("%d", &g);
    REP(i, 0, g)
    {
        scanf("%s %s %s", &n1, &n2, &n3);
        groups[n1] = i;
        groups[n2] = i;
        groups[n3] = i;
    }

    REP(i, 0, t)
    {
        if (groups[t1[i]] != groups[t2[i]])
        {
            v++;
        }
    }
    REP(i, 0, s)
    {
        if (groups[s1[i]] == groups[s2[i]])
        {
            v++;
        }
    }

    printf("%d", v);
}