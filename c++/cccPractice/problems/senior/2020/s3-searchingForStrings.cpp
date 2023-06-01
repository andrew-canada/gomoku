// q: analyze the complexity of the code snippet below
// a: O(n!)
// q: is there a faster way to implement this?
// a: yes, use the snippet in c++\cccPractice\problems\senior\2020\test.cpp
// q: which line of the code snippet below is the bottleneck?
// a: line 1
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
    n[len - 1] = '\0';
    std::sort(n, n + len - 1);
    do
    {
        if (strstr(h, n) != NULL)
        {
            num++;
        }
    } while (std::next_permutation(n, n + len - 1));
    printf("%d", num);
}