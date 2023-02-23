#include <stdio.h>
#include <map>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

void printMap(const map<int, vector<int>> &inputMap)
{
    for (auto const &a : inputMap)
    {
        cout << a.first << " ";
        vector<int> tempVector = a.second;
        int size = tempVector.size();
        for (int i = 0; i < size; i++)
        {
            cout << tempVector[i] << " ";
        }
        cout << endl;
    }
}

vector<int> getAdjacent(map<int, vector<int>> &inputGraph, const int page)
{
    map<int, vector<int>>::iterator it = inputGraph.find(page);
    return it->second;
}

int main()
{
    map<int, vector<int>> graph;
    unsigned int n;
    // scanf("%d", &n);
    cin >> n;
    int val, vectorVal;
    set<int> values;
    set<int> path;

    for (unsigned int i = 1; i <= n; i++)
    {
        // scanf("%d", &val);
        cin >> val;
        if (val == 0)
        {
            graph[i].push_back(0);
        }
        for (int j = 0; j < val; j++)
        {
            // can only use scanf to get everything in one go, not many layers
            // scanf("%d", vectorVal);
            cin >> vectorVal;
            graph[i].push_back(vectorVal);
            if (vectorVal != 1 && vectorVal != i)
            {
                values.insert(vectorVal);
            }
            if (i == 1)
            {
                path.insert(vectorVal);
            }
        }
    }

    cout << ((n - 1 == values.size()) ? "Y" : "N");

    cout << endl;

    int pathLength = 1;

    set<int> path2;
    set<int> tempSet;
    while (path.find(0) == path.end())
    {
        pathLength += 1;
        for (int const i : path)
        {
            vector<int> val = graph[i];
            copy(val.begin(), val.end(), inserter(tempSet, tempSet.end()));
        }
        path.clear();
        path.insert(tempSet.begin(), tempSet.end());
        tempSet.clear();
    }
    cout << pathLength;
}