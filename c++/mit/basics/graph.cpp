#include <iostream>
#include <vector>

using namespace std;

// adjacency matrix
void printMatrix(int matrix[][6], int nodes, int edges)
{
    cout << "printing matrix:" << endl;
    for (int i = 1; i <= nodes; i++)
    {
        for (int j = 1; j <= nodes; j++)
        {
            cout << matrix[i][j] << " ";
        }
        cout << endl;
    }
}

// adjacency list
void addEdge(vector<int> inputVector[], int node1, int node2)
{
    inputVector[node1].push_back(node2);
    inputVector[node2].push_back(node1);
}

void printGraph(vector<int> inputVector[], int nodes)
{
    for (int i = 0; i < nodes; i++)
    {
        cout << "vertex " << i << ": ";
        for (int j : inputVector[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }
}

int main()
{
    // adjacency matrix
    int matrixNodes = 5, edges = 4;
    int adjMat[6][6];
    for (int i = 0; i < 4; i++)
    {
        int u, v;
        cin >> u >> v;
        adjMat[u][v] = 1;
        adjMat[v][u] = 1;
    }
    printMatrix(adjMat, 5, 4);

    // adjecency list
    int listNodes = 5;
    vector<int> adjecencyVector[5];
    addEdge(adjecencyVector, 0, 1);
    addEdge(adjecencyVector, 1, 2);
    addEdge(adjecencyVector, 2, 3);
    addEdge(adjecencyVector, 3, 4);
    printGraph(adjecencyVector, listNodes);
}