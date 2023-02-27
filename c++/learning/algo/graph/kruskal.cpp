#include <stdio.h>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

typedef tuple<int, int, int> iii;
typedef vector<int> vi;
#define REP(i, a, b) for (int i = int(a); i <= int(b - 1); i++)

vector<iii> edgeList;
vi ufdSet;
int nodes, edges;
int n1, n2, w;
int totWeight, numTaken = 1;

void initSet(int sz);
int findSet(int n);
bool isSameSet(int a, int b);
void unionSet(int a, int b);

int main()
{
    freopen("mst_in.txt", "r", stdin);

    scanf("%d %d", &nodes, &edges);
    edgeList.resize(edges);
    REP(i, 0, edges)
    {
        scanf("%d %d %d", &n1, &n2, &w);
        edgeList[i] = {w, n1, n2};
    }

    sort(edgeList.begin(), edgeList.end());
    initSet(nodes);
    REP(i, 0, edges)
    {
        auto &[wt, nd1, nd2] = edgeList[i];
        if (!isSameSet(nd1, nd2))
        {
            totWeight += wt;
            unionSet(nd1, nd2);
            numTaken++;
            if (numTaken == nodes)
            {
                break;
            }
        }
    }

    printf("Total weight of minimum spanning tree: %d", totWeight);
}

void initSet(int sz)
{
    ufdSet.resize(sz);
    REP(i, 0, sz) { ufdSet[i] = i; }
}

int findSet(int n)
{
    return (ufdSet[n] == n ? n : ufdSet[n] = findSet(ufdSet[n]));
}

bool isSameSet(int a, int b)
{
    return (findSet(a) == findSet(b));
}

void unionSet(int a, int b)
{
    int x = findSet(a);
    int y = findSet(b);
    ufdSet[a] = b;
}