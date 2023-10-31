#include <stdio.h>
#include <string>
#include <unordered_map>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

int s, d, g;
char p1[15], p2[15], p3[15];
string same1[100005], same2[100005];
string diff1[100005], diff2[100005];
unordered_map<string, int> groups;
int v;

int main()
{
    scanf("%d", &s);
    REP(i, 0, s - 1)
    {
        scanf("%s%s", &p1, &p2);
        same1[i] = p1, same2[i] = p2;
    }
    scanf("%d", &d);
    REP(i, 0, d - 1)
    {
        scanf("%s%s", &p1, &p2);
        diff1[i] = p1, diff2[i] = p2;
    }

    scanf("%d", &g);
    REP(i, 0, g - 1)
    {
        scanf("%s%s%s", &p1, &p2, &p3);
        groups[p1] = i, groups[p2] = i, groups[p3] = i;
    }

    REP(i, 0, s - 1)
    {
        if (groups[same1[i]] != groups[same2[i]])
        {
            v++;
        }
    }
    REP(i, 0, d - 1)
    {
        if (groups[diff1[i]] == groups[diff2[i]])
        {
            v++;
        }
    }
    printf("%d", v);
}