#include <stdio.h>

int roman[90];
int tot;
char num[25];
int sz;

int main()
{
    roman['I'] = 1;
    roman['V'] = 5;
    roman['X'] = 10;
    roman['L'] = 50;
    roman['C'] = 100;
    roman['D'] = 500;
    roman['M'] = 1000;
    scanf("%s", &num);
    sz = sizeof(num) / sizeof(num[0]);
    for (int i = 1; i < sz; i += 2)
    {
        if (i < sz - 2)
        {
            if (roman[num[i]] < roman[num[i + 2]])
            {
                tot = tot - 2 * (num[i - 1] - '0') * (roman[num[i]]);
            }
        }
        tot = tot + (num[i - 1] - '0') * (roman[num[i]]);
    }
    printf("%d", tot);
}