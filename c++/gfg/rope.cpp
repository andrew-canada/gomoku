// solve rope cutting problem with c++ solver
// given n as rope length and a, b, c as cut lengths
// find the maximum number of cuts
// using recursive algorithm
// write function rope

#include <iostream>
#include <algorithm>

using namespace std;

int rope(int n, int a, int b, int c);

int main()
{
    int n, a, b, c;
    cin >> n >> a >> b >> c;
    if (n == 0)
    {
        return 0;
    }
    if (n < 0)
    {
        return -1;
    }
    int res = max(max(rope(n - a, a, b, c), rope(n - b, a, b, c)), rope(n - c, a, b, c));
    if (res == -1)
    {
        return -1;
    }
    return res + 1;
}

int rope(int n, int a, int b, int c)
{
    if (n == 0)
    {
        return 0;
    }
    if (n < 0)
    {
        return -1;
    }
    int res = max(max(rope(n - a, a, b, c), rope(n - b, a, b, c)), rope(n - c, a, b, c));
    if (res == -1)
    {
        return -1;
    }
    return res + 1;
}