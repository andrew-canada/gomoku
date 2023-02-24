#include <stdio.h>
#include <bitset>
#include <iostream>
#include <string>

using namespace std;

#define LOCAL

int n;
int tmp;
bitset<32> midL1("00000000111111110000000000000000");
bitset<32> midR1("00000000000000001111111100000000");

int main()
{
#ifdef LOCAL
    freopen("594.in", "r", stdin);
    freopen("594.out", "w", stdout);
#endif
    while (scanf("%d", &n) != EOF)
    {
        bitset<32> binNum(n);

        bitset<32> left(binNum >> 24);
        bitset<32> right(binNum << 24);
        bitset<32> midL((binNum << 8) & midL1);
        bitset<32> midR((binNum >> 8) & midR1);

        printf("%d converts to %d\n", n, left | right | midL | midR);
    }
}