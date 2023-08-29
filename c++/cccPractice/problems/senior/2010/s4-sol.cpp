#include <iostream>
#include <vector>
#include <algorithm>
#include <map>
using namespace std;
using namespace std;
#define scan(x)                                                                   \
    do                                                                            \
    {                                                                             \
        while ((x = getchar()) < '0')                                             \
            ;                                                                     \
        for (x -= '0'; '0' <= (_ = getchar()); x = (x << 3) + (x << 1) + _ - '0') \
            ;                                                                     \
    } while (0)
char _;

const int maxN = 101;
const int maxPenEdge = 8;
int N;
int component[maxN];
int costs[maxPenEdge];
int corners[maxPenEdge];
int costOutside;
int costInside;
int numComps;
struct Edge
{
    int u;
    int v;
    int cost;
    bool operator<(const Edge &comp) const
    {
        if (u < comp.u)
            return true;
        if (u > comp.u)
            return false;
        if (v < comp.v)
            return true;
        if (v > comp.v)
            return false;
        return cost < comp.cost;
    }
    bool operator==(const Edge &comp) const
    { // Don't need, but speeds up not doing this comp
        return (u == comp.u) && (v == comp.v);
    }
};
map<Edge, int> edgeMap; // Here edges with corners as u,v, value is the pen
vector<Edge> edges;     // Here edges with pens listed as u,v

void AddEdge(int pen, int corn1, int corn2, int cost)
{
    if (corn2 < corn1)
    {
        AddEdge(pen, corn2, corn1, cost);
        return;
    }
    auto found = edgeMap.emplace(Edge{corn1, corn2, cost}, pen);
    if (!found.second)
    {
        int pen2 = found.first->second;
        edges.push_back(Edge{pen, pen2, cost});
        // edgeMap.erase(found.first);
        found.first->second = -1;
    }
}

void InitComps()
{
    for (int i = 0; i <= N; i++)
    {
        component[i] = i;
    }
}

int FindComponent(int u)
{ // Goes down line to retrieve msg
    if (component[u] != u)
    {
        component[u] = FindComponent(component[u]);
    }
    return component[u];
}

void SetComponent(int u, int cv)
{ // Sends msg down line
    int next = component[u];
    component[u] = cv;
    if (next != u)
    {
        SetComponent(next, cv);
    }
}

bool CheckAdd(int u, int v)
{
    int cu = FindComponent(u);
    int cv = FindComponent(v);
    if (cu != cv)
    { // Don't care about labelling with lesser one
        SetComponent(u, cv);
        return true;
    }
    return false;
}

int main()
{
    scan(N);
    if (N <= 1)
    {
        cout << 0 << "\n";
        return 0;
    }
    for (int i = 1; i <= N; i++)
    {
        int numEdge;
        scan(numEdge);
        for (int j = 0; j < numEdge; j++)
        {
            scan(corners[j]);
        }
        for (int j = 0; j < numEdge; j++)
        {
            scan(costs[j]);
        }
        for (int j = 0; j < numEdge - 1; j++)
        {
            int corn1 = corners[j];
            int corn2 = corners[j + 1];
            AddEdge(i, corn1, corn2, costs[j]);
        }
        AddEdge(i, corners[0], corners[numEdge - 1], costs[numEdge - 1]);
    }
    for (auto &el : edgeMap)
    {
        int pen = el.second;
        if (pen > 0)
        {
            int cost = el.first.cost;
            edges.push_back(Edge{0, pen, cost});
        }
    }
    sort(edges.begin(), edges.end(),
         [](Edge e1, Edge e2) -> bool
         {
             return e1.cost < e2.cost;
         });
    numComps = 1 + N; // First handle joining to outside
    InitComps();
    for (auto &e : edges)
    {
        if (CheckAdd(e.u, e.v))
        {
            numComps--;
            costOutside += e.cost;
            if (numComps <= 1)
                break;
        }
    }
    numComps = N;
    InitComps();
    for (auto &e : edges)
    {
        if (e.u != 0)
        {
            if (CheckAdd(e.u, e.v))
            {
                numComps--;
                costInside += e.cost;
                if (numComps <= 1)
                    break;
            }
        }
    }
    if (numComps <= 1)
    {
        cout << min(costInside, costOutside) << "\n";
    }
    else
    {
        cout << costOutside << "\n";
    }
}