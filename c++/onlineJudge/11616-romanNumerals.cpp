#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <utility>

// #define LOCAL

using namespace std;

typedef pair<string, int> psi;

int symb[100];
vector<psi> val = {{"M", 1000}, {"CM", 900}, {"D", 500}, {"CD", 400}, {"C", 100}, {"XC", 90}, {"L", 50}, {"XL", 40}, {"X", 10}, {"IX", 9}, {"V", 5}, {"IV", 4}, {"I", 1}};

int main()
{
#ifdef LOCAL
    freopen("11616.in", "r", stdin);
#endif
    symb['I'] = 1;
    symb['V'] = 5;
    symb['X'] = 10;
    symb['L'] = 50;
    symb['C'] = 100;
    symb['D'] = 500;
    symb['M'] = 1000;

    string num;
    while (getline(cin, num))
    {
        if (isdigit(num[0]))
        {
            int arab = stoi(num);
            for (auto &[c, v] : val)
            {
                while (arab >= v)
                {
                    printf("%s", c.c_str());
                    arab -= v;
                }
            }
        }
        else
        {
            int tot = 0;
            for (int i = 0; i < num.length(); i++)
            {
                if (num[i + 1] && symb[num[i]] < symb[num[i + 1]])
                {
                    tot += symb[num[i + 1]] - symb[num[i]];
                    i++;
                }
                else
                {
                    tot += symb[num[i]];
                }
            }
            printf("%d", tot);
        }
        printf("\n");
    }
}