#include <bits/stdc++.h>
using namespace std;

char ts[100005];

int getPoints(string &s, string str, int val)
{
    int res = 0, i = 0;
    for (int j = 0; j < s.size(); j++)
    {
        s[i++] = s[j];
        if (i >= 2 && s[i - 2] == str[0] && s[i - 1] == str[1])
        {
            res += val;
            i -= 2;
        }
    }
    s.resize(i);
    return res;
}

int main()
{
    int t;
    int x, y;
    int temp;
    string s1, s2;
    scanf("%d", &t);
    while (t--)
    {
        scanf("%s", &ts);
        string s(ts);
        scanf("%d%d", &x, &y);
        if (x > y)
        {
            s1 = "01", s2 = "10";
        }
        else
        {
            s1 = "10", s2 = "01";
            temp = x;
            x = y, y = temp;
        }
        printf("%d\n", getPoints(s, s1, x) + getPoints(s, s2, y));
    }
    return 0;
}

/*
2
010101
1 4
1100
2 2
*/