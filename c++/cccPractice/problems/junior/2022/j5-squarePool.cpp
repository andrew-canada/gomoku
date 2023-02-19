#include <iostream>
#include <algorithm>
#include <vector>
#include <utility>

using namespace std;

//#define LOCAL

bool sortPairByFirst(pair<int, int> &p1, pair<int, int> &p2)
{
    return p1.first < p2.first;
}

int findMaxDifferenceBetweenElements(vector<int> &input)
{
    int maxColumnDistance = input.at(1) - input.at(0);
    for (int i = 2; i < input.size(); i++)
    {
        int tempDifference = input.at(i) - input.at(i - 1);
        if (tempDifference > maxColumnDistance)
        {
            maxColumnDistance = tempDifference;
        }
    }
    return maxColumnDistance - 1;
}

int main()
{
    ios_base::sync_with_stdio(false);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    int poolSideLength = 0;
    int numberOfTrees = 0;
    int maxColumnDistance = 0;
    vector<pair<int, int>> trees;
    vector<int> treeColumns;
    int maxPoolLength = 0;
    int tempMaxPoolLength = 0;

    cin >> poolSideLength >> numberOfTrees;

    trees.push_back(make_pair(0, 0));
    trees.push_back(make_pair(poolSideLength + 1, poolSideLength + 1));

    for (int i = 0; i < numberOfTrees; i++)
    {
        int row, column;
        cin >> row >> column;
        trees.push_back(make_pair(row, column));
    }
    sort(trees.begin(), trees.end(), sortPairByFirst);

    for (int i = 0; i < trees.size(); i++)
    {
        treeColumns.clear();
        treeColumns.push_back(0);
        treeColumns.push_back(poolSideLength + 1);

        for (int j = i + 1; j < trees.size(); j++)
        {
            sort(treeColumns.begin(), treeColumns.end());
            maxColumnDistance = findMaxDifferenceBetweenElements(treeColumns);

            tempMaxPoolLength = min(maxColumnDistance, trees.at(j).first - trees.at(i).first - 1);
            maxPoolLength = max(maxPoolLength, tempMaxPoolLength);
            treeColumns.push_back(trees.at(j).second);
        }
    }
    cout << maxPoolLength;
}