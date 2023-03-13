#include <stdio.h>

using namespace std;

#define LOCAL

int main()
{
#ifdef LOCAL
    freopen("11235.in", "r", stdin);
    freopen("11235.out", "w", stdout);
#endif
}