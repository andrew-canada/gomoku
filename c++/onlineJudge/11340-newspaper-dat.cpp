#include <stdio.h>
#include <string>
#include <iostream>
#include <cstring>
#include <map>

using namespace std;

#define LOCAL

int cases, lines;
char c;
int n;
char cost[256];
string str;
// map<char, int> cost;

int main()
{
#ifdef LOCAL
    freopen("11340-1.in", "r", stdin);
    freopen("11340.out", "w", stdout);
#endif

    scanf("%d", &cases);
    while (cases--)
    {
        memset(cost, 0, 256);
        // cost.clear();
        double tot = 0;
        scanf("%d", &lines);
        while (lines--)
        {
            scanf(" %s %d", &c, &n);
            cost[c + 128] = n;
        }
        scanf("%d", &lines);

        getline(cin, str);
        while (lines--)
        {
            getline(cin, str);
            for (char c : str)
            {
                tot += (cost[c + 128]);
            }
        }
        printf("%.2f$\n", tot / 100);
    }
}