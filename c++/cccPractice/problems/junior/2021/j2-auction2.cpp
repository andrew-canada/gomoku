#include <stdio.h>
#include <string>

char name[50];

int main()
{
    int n;
    scanf("%d", &n);
    int d;
    int ma = 0;
    std::string ans;
    for (int i = 0; i < n; i++)
    {
        scanf("%s%d", &name, &d);
        if (d > ma)
        {
            ma = d;
            std::string mn(name);
            ans = mn;
        }
    }
    printf("%s", ans.c_str());
}