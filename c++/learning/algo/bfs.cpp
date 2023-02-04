#include <stdio.h>
#include <vector>
#include <queue>

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

    void bfs(int startNode, int targetNode)
    {
        std::vector<bool> visited;
        visited.resize(numNodes, false);
        std::queue<int> positions;

        positions.push(startNode);
        visited[startNode] = true;

        while (!positions.empty())
        {
            startNode = positions.front();
            if (startNode == targetNode)
            {
                printf("found");
                return;
            }
            printf("%d ", startNode);
            positions.pop();

            for (int curAdj : adjNodes[startNode])
            {
                if (!visited[curAdj])
                {
                    positions.push(curAdj);
                    visited[curAdj] = true;
                }
            }
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

    g1.bfs(0, 3);
    printf("\n");
    g1.bfs(0, 31);
}