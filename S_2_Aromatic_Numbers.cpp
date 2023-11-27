#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

char num[25];
int r[200];
int val;

int main()
{
    scanf("%s", &num);
    r['I'] = 1;
    r['V'] = 5;
    r['X'] = 10;
    r['L'] = 50;
    r['C'] = 100;
    r['D'] = 500;
    r['M'] = 1000;
    int len = strlen(num);
    for (int i = 0; i < len; i += 2)
    {
        if (r[num[i + 3]] > r[num[i + 1]])
        {
            val -= (num[i] - '0') * r[num[i + 1]];
        }
        else
        {
            val += (num[i] - '0') * r[num[i + 1]];
        }
    }
    printf("%d", val);
}