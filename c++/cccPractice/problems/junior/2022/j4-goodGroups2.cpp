#include <stdio.h>
#include <map>
#include <string>

#define LOCAL

std::string fl[100000];
std::string fr[100000];
std::string el[100000];
std::string er[100000];
std::map<std::string, int> groups;

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    int f, e, g;
    int v = 0;
    char name[12];
    scanf("%d", &f);
    for (int i = 0; i < f; i++)
    {
        scanf("%s", &name);
        std::string nameStr(name);
        fl[i] = nameStr;

        scanf("%s", &name);
        std::string nameStr2(name);
        fr[i] = nameStr2;
    }

    scanf("%d", &e);
    for (int i = 0; i < e; i++)
    {
        scanf("%s", &name);
        std::string nameStr(name);
        el[i] = nameStr;

        scanf("%s", &name);
        std::string nameStr2(name);
        er[i] = nameStr2;
    }

    scanf("%d", &g);
    for (int i = 0; i < g; i++)
    {
        scanf("%s", &name);
        std::string nameStr(name);
        groups[nameStr] = i;

        scanf("%s", &name);
        std::string nameStr2(name);
        groups[nameStr2] = i;

        scanf("%s", &name);
        std::string nameStr3(name);
        groups[nameStr3] = i;
    }

    for (int j = 0; j < f; j++)
    {
        if (groups[fl[j]] != groups[fr[j]])
        {
            v += 1;
        }
    }
    for (int j = 0; j < e; j++)
    {
        if (groups[el[j]] == groups[er[j]])
        {
            v += 1;
        }
    }

    printf("%d", v);
}