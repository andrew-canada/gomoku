// implementation of a O(n) next permutation algorithm
// q: what is the time complexity of this snippet?
// a: O(n)
// q: is the time complexity O(N!) if I want to print all permutations?
// a: no, it is O(N * N!)
#include <stdio.h>
#include <cstring>
#include <algorithm>

using namespace std;

void nextPermutation(char *begin, char *end)
{
    char *p = end;
    while (p > begin && *(p - 1) > *p)
    {
        p--;
    }
    if (p == begin)
    {
        reverse(begin, end + 1);
    }
    else
    {
        char *q = p;
        q--;
        while (p < end && *q < *p)
        {
            p++;
        }
        p--;
        swap(*p, *q);
        reverse(q + 1, end + 1);
    }
}

int main()
{
    char str[] = "abc";
    do
    {
        printf("%s\n", str);
        nextPermutation(str, str + 2);
    } while (strcmp(str, "cba"));
    return 0;
}
