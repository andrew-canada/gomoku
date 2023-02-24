#include <stdio.h>
#include <string>
#include <iostream>
#include <cstring>
#include <unordered_map>

using namespace std;

// #define LOCAL

int cases, lines;
char c;
int n;
string str;
unordered_map<char, int> cost;

int main()
{
#ifdef LOCAL
    freopen("11340-1.in", "r", stdin);
    freopen("11340.out", "w", stdout);
#endif

    scanf("%d", &cases);
    while (cases--)
    {
        cost.clear();
        double tot = 0;
        scanf("%d", &lines);
        while (lines--)
        {
            scanf(" %c %d", &c, &n);
            cost[c] = n;
        }
        scanf("%d", &lines);

        getline(cin, str);
        while (lines--)
        {
            getline(cin, str);
            for (char c : str)
            {
                tot += (cost[c]);
            }
        }
        printf("%.2f$\n", tot / 100);
    }
}