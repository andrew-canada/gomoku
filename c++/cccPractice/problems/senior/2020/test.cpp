// permutation of string with better performance than n !(n !is factorial)
// q:what is the time complexity of this snippet?
// a:O(n!)
#include <stdio.h>
#include <cstring>
#include <algorithm>

using namespace std;

void permutation(char *str, char *begin, char *end)
{
    if (begin == end)
    {
        printf("%s\n", str);
    }
    else
    {
        for (char *ch = begin; ch <= end; ch++)
        {
            swap(*ch, *begin);
            permutation(str, begin + 1, end);
            swap(*ch, *begin);
        }
    }
}

int main()
{
    char str[] = "abc";
    permutation(str, str, str + 2);
    return 0;
}