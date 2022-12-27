#include <iostream>
#include <map>
#include <vector>
#include <stdexcept>
#include <iterator>

using namespace std;

class Graph
{
private:
    map<int, vector<int>> graph;

public:
    Graph(const vector<int> &starts, const vector<int> &ends)
    {
        if (starts.size() != ends.size())
        {
            throw std::invalid_argument("different lengths");
        }
        else
        {
            for (int i = 0; i < starts.size(); i++)
            {
                int start = starts[i];
                int end = ends[i];
                graph[start].push_back(end);
            }
        }
    }
    const vector<int> &adjacent(const int nodeID) const
    {
        map<int, vector<int>>::const_iterator it = graph.find(nodeID);
        if (it == graph.end())
        {
            throw std::invalid_argument("id doesnt exist");
        }
        return it->second;
    }
    int numOutgoing(const int nodeID) const
    {
        return adjacent(nodeID).size();
    }
};

int main()
{
    vector<int> starts = {1, 1, 1, 5, 5, 4};
    vector<int> ends = {2, 3, 4, 4, 2, 2};
    Graph g1(starts, ends);
    for (int i : g1.adjacent(4))
    {
        cout << i << " ";
    }
    cout << endl;
    cout << g1.numOutgoing(2);
}