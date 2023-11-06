#include <stdio.h>
using namespace std;

bool freq[1000005];

int main()
{
    bool found;
    int t, n;
    int val;
    scanf("%d", &t);
    for (int i = 0; i < t; i++)
    {
        scanf("%d", &n);
        for (int j = 0; j < n; j++)
        {
            scanf("%d", val);
            if (freq[val])
            {
                printf("%d\n", val);
                found = 1;
                break;
            }
            freq[val] = 1;
        }
        if (!found)
        {
            printf("-1\n");
        }
        found = 0;
    }
    return 0;
}