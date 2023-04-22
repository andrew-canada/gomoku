#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define ALL(v) v.begin(), v.end()

int n;
vector<char> letters = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'};

int fact(int n)
{
    if (n == 1)
    {
        return 1;
    }
    return n * fact(n - 1);
}

int main()
{
    do
    {
        // for (auto &v : letters)
        // {
        //     printf("%c ", v);
        // }
        // printf("\n");
        n++;
    } while (next_permutation(ALL(letters)));
    printf("%d", n == fact(10));
}