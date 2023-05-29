#include <stdio.h>
#include <cstring>
#include <algorithm>

#define LOCAL

char n[200005];
char h[200005];
int num;

int main()
{
#ifdef LOCAL
    freopen("s3.in", "r", stdin);
#endif
    fgets(n, 200005, stdin);
    fgets(h, 200005, stdin);
    int len = strlen(n);
    do
    {
        if (strstr(h, n) != NULL)
        {
            num++;
        }
    } while (std::next_permutation(n, n + len - 1));
    printf("%d", num);
}