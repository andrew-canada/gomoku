#include <stdio.h>
#include <tuple>
#include <set>

using namespace std;

typedef tuple<int, int, int> iii;

int main()
{
    multiset<iii> bd;
    bd.emplace(4, 2, -2000);
    bd.emplace(4, 2, -2000);
    bd.emplace(4, 2, -1900);
    bd.emplace(4, 1, -2000);
    bd.emplace(6, 28, -2000);
    bd.emplace(9, 28, -2000);
    bd.emplace(10, 18, -1000);
    for (auto &v : bd)
    {
        printf("%d/%d/%d ", get<1>(v), get<0>(v), -get<2>(v));
    }
    puts("");
    for (auto &[m, d, y] : bd)
    {
        printf("%d/%d/%d ", d, m, -y);
    }
}