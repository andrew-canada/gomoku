#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <stack>

class Graph
{
private:
    int numNodes;
    std::vector<std::vector<int>> adjNodes;

public:
    Graph(int numNodes)
    {
        this->numNodes = numNodes;
        adjNodes.resize(numNodes);
    }

    void addEdge(int root, int node)
    {
        adjNodes[root].push_back(node);
    }

    void dfs(int startNode, int targetNode)
    {
        std::unordered_map<int, bool> visited;
        std::stack<int> nodePath;
        bool adjFound = false;

        nodePath.push(startNode);
        visited[startNode] = true;

        while (!nodePath.empty())
        {
            startNode = nodePath.top();
            if (startNode == targetNode)
            {
                printf("found");
                return;
            }

            for (int curAdj : adjNodes[startNode])
            {
                if (!visited[curAdj])
                {
                    adjFound = true;
                    nodePath.push(curAdj);
                    visited[curAdj] = true;
                    break;
                }
            }
            if (!adjFound)
            {
                nodePath.pop();
            }
            adjFound = false;
            printf("%d:%d ", visited.size(), startNode);
        }
        printf("not found");
    }
};

int main()
{
    Graph g1(6);
    g1.addEdge(0, 1);
    g1.addEdge(0, 2);
    g1.addEdge(1, 3);
    g1.addEdge(3, 4);
    g1.addEdge(2, 5);
    g1.addEdge(1, 5);

    g1.dfs(0, 3);
    printf("\n");
    g1.dfs(0, 31);
}