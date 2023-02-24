#include <stdio.h>
#include <map>
#include <string>
#include <cstdio>
#include <cstring>

#define LOCAL

using namespace std;

map<string, int> tm;
int n;
char name[31];

int main()
{
#ifdef LOCAL
    freopen("10226-2.in", "r", stdin);
    freopen("10226.out", "w", stdout);
#endif
    scanf("%d", &n);
    scanf("%d");
    while (n--)
    {
        tm.clear();
        int tot = 0;
        memset(name, 0, sizeof(name));
        int num = scanf("%31[^\n]%*c", &name);

        while (num == 1 && strlen(name) != 0)
        {
            string s(name);
            tm[s]++;
            tot++;
            num = scanf("%31[^\n]%*c", &name);
        }
        for (auto it = tm.begin(); it != tm.end(); it++)
        {
            printf("%s %.4f\n", it->first.c_str(), (double)it->second / tot * 100);
        }
    }
}