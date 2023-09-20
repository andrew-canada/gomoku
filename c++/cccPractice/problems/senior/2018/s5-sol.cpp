#include <iostream>
#include <algorithm>
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

const int maxSize = 100001;
const int maxEdges = 200002;
int compCities[maxSize]; // Since M and N have same bound
int compPlanets[maxSize];
long long savings = 0;
int nPlanets, nCities, nFlights, nPortals, nEdges;
int numCityComps, numPlanetComps;

struct Edge
{
    int u;
    int v;
    int cost;
    bool isPortal;
};
Edge edges[maxEdges];

int FindComponent(int u, bool isPlanet)
{ // Goes down line to retrieve msg
    int *component;
    if (isPlanet)
    {
        component = compPlanets;
    }
    else
    {
        component = compCities;
    }
    if (component[u] != u)
    {
        component[u] = FindComponent(component[u], isPlanet);
    }
    return component[u];
}

void SetComponent(int u, int v, bool isPlanet)
{ // Sends msg done line
    int *component;
    if (isPlanet)
    {
        component = compPlanets;
    }
    else
    {
        component = compCities;
    }
    if (component[u] < component[v])
    {
        SetComponent(v, u, isPlanet);
    }
    else
    {
        int next = component[u];
        component[u] = component[v];
        if (next != u)
        {
            SetComponent(next, v, isPlanet);
        }
    }
}

void CheckAdd(int index)
{
    Edge e = edges[index];
    bool isPlanet = e.isPortal;
    int u = e.u;
    int v = e.v;
    if (FindComponent(u, isPlanet) != FindComponent(v, isPlanet))
    {
        int numEdges;
        if (isPlanet)
        {
            numEdges = numCityComps;
            numPlanetComps--;
        }
        else
        {
            numEdges = numPlanetComps;
            numCityComps--;
        }
        savings -= (long long)numEdges * e.cost;
        SetComponent(u, v, isPlanet);
    }
}

int main()
{
    scan(nPlanets);
    scan(nCities);
    scan(nFlights);
    scan(nPortals);
    nEdges = nFlights + nPortals;
    for (int i = 0; i < nFlights; i++)
    {
        int u;
        scan(u);
        int v;
        scan(v);
        int cost;
        scan(cost);
        savings += (long long)cost * nPlanets;
        edges[i] = {u, v, cost, false};
    }
    for (int i = nFlights; i < nEdges; i++)
    {
        int u;
        scan(u);
        int v;
        scan(v);
        int cost;
        scan(cost);
        savings += (long long)cost * nCities;
        edges[i] = {u, v, cost, true};
    }
    for (int i = 0; i < nPlanets; i++)
    {
        compPlanets[i] = i;
    }
    for (int i = 0; i < nCities; i++)
    {
        compCities[i] = i;
    }
    sort(edges, edges + nEdges,
         [](const Edge &e1, const Edge &e2) -> bool
         {
             return e1.cost < e2.cost;
         });
    numCityComps = nCities;
    numPlanetComps = nPlanets;
    int index = 0;
    while (numCityComps > 1 || numPlanetComps > 1)
    { // Don't need extra cond since have assurance that connected
        CheckAdd(index);
        index++;
    }
    cout << savings << "\n";
}