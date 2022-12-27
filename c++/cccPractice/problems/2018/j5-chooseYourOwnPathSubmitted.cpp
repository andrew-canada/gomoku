#include <map>
#include <vector>
#include <iostream>
#include <set>

using namespace std;

int main()
{
    map<int, vector<int>> graph;
    unsigned int n;
    cin >> n;
    int val, vectorVal;
    set<int> values;
    set<int> path;

    for (unsigned int i = 1; i <= n; i++)
    {
        cin >> val;
        if (val == 0)
        {
            graph[i].push_back(0);
        }
        for (int j = 0; j < val; j++)
        {
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