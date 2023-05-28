#include <stdio.h>
#include <cstring>
#include <algorithm>

char n[200005];
char h[200005];
int num;

int main()
{
    fgets(n, 200005, stdin);
    fgets(h, 200005, stdin);
    int len = strlen(n);
    n[len - 1] = '\0';
    std::sort(n, n + len - 1);
    do
    {
        if (strstr(h, n) != nullptr)
        {
            num++;
        }
    } while (std::next_permutation(n, n + len - 1));
    printf("%d", num);
}