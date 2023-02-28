#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <utility>

using namespace std;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vii edges;
string edge;
int cases;
char maxNode;

int main()
{
    edges.resize(100);
    scanf("%d", &cases);
    while (cases--)
    {
        scanf(" %c", &maxNode);
        vi edgeList(maxNode);

        while (getline(cin, edge), !edge.empty())
        {
            edges[0] = {edge[0], edge[1]};
        }

        edges.clear();
    }
}