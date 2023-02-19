#include <stdio.h>
#include <vector>
#include <utility>
#include <algorithm>

#define min(a, b) (a < b ? a : b)
#define max(a, b) (a > b ? a : b)

std::vector<std::pair<int, int>> trees;
std::vector<int> treeCol;

bool sortByX(std::pair<int, int> p1, std::pair<int, int> p2)
{
    return p1.first < p2.first;
}

int maxYDist(std::vector<int> treeCol)
{
    int max = 0;
    int d;
    for (int i = 0; i < treeCol.size() - 1; i++)
    {
        d = treeCol.at(i + 1) - treeCol.at(i) - 1;
        if (d > max)
        {
            max = d;
        }
    }
    return max;
}

int main()
{
    int sz, nt;
    int x, y;
    int maxL = 0, tmp;
    scanf("%d%d", &sz, &nt);
    trees.push_back(std::make_pair(0, 0));
    for (int i = 0; i < nt; i++)
    {
        scanf("%d %d", &x, &y);
        trees.push_back(std::make_pair(x, y));
    }
    std::sort(trees.begin(), trees.end(), sortByX);
    // std::for_each(trees.begin(), trees.end(), [](std::pair<int, int> p)
    //               { printf("%d %d\n", p.first, p.second); });
    trees.push_back(std::make_pair(sz + 1, sz + 1));

    for (int i = 0; i < nt + 1; i++)
    {
        treeCol.clear();
        treeCol.push_back(0);
        treeCol.push_back(sz + 1);
        for (int j = i + 1; j < nt + 2; j++)
        {
            std::sort(treeCol.begin(), treeCol.end());
            int yd = maxYDist(treeCol);
            tmp = min(yd, trees.at(j).first - trees.at(i).first - 1);
            maxL = max(maxL, tmp);
            treeCol.push_back(trees.at(j).second);
        }
    }
    printf("%d", maxL);
}