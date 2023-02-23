#include <stdio.h>
#include <map>
#include <string>
#include <cstdio>
#include <cstring>
#include <iostream>

// #define LOCAL

using namespace std;

map<string, int> tm;
int n;
string name;

int main()
{
#ifdef LOCAL
    freopen("10226-3.in", "r", stdin);
    freopen("10226-3.out", "w", stdout);
#endif
    scanf("%d", &n);
    scanf("%d");
    while (n--)
    {
        tm.clear();
        int tot = 0;
        while (getline(cin, name), !name.empty())
        {
            tm[name]++;
            tot++;
        }
        for (auto it = tm.begin(); it != tm.end(); it++)
        {
            printf("%s %.4f\n", it->first.c_str(), (double)it->second / tot * 100);
        }
        if (n != 0)
        {
            printf("\n");
        }
    }
}