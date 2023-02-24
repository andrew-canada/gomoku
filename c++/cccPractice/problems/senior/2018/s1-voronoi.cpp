#include <stdio.h>
#include <algorithm>

#define min(a, b) (a < b ? a : b)

int n;
int villages[100];
double minSize = 2000000005;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &villages[i]);
    }
    std::sort(villages, villages + n);
    for (int i = 1; i < n - 1; i++)
    {
        minSize = min(minSize, ((double)villages[i] + villages[i + 1]) / 2 - ((double)villages[i] + villages[i - 1]) / 2);
    }
    printf("%.1f", minSize);
}