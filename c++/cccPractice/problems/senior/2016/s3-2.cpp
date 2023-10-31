#include <stdio.h>
#include <vector>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

int n, m;
bool isPho[100005];
vector<int> adjL[100005];
int numPho, maxDiam;
int start;

void markPho(int node, int par);
void getDiam(int node, int par, int diam);

int main()
{
    scanf("%d%d", &n, &m);
    int p;
    REP(i, 0, m)
    {
        scanf("%d", &p);
        isPho[p] = true;
    }
    int n1, n2;
    REP(i, 0, n - 1)
    {
        scanf("%d%d", &n1, &n2);
        adjL[n1].push_back(n2);
        adjL[n2].push_back(n1);
    }
    markPho(p, -1);
    getDiam(p, -1, 0);
    getDiam(start, -1, 0);
    for (bool b : isPho)
    {
        if (b)
        {
            numPho++;
        }
    }
    printf("%d", 2 * (numPho - 1) - maxDiam);
}

void markPho(int node, int par)
{
    for (int n1 : adjL[node])
    {
        if (n1 != par)
        {
            markPho(n1, node);
            if (isPho[n1])
            {
                isPho[node] = true;
            }
        }
    }
}

void getDiam(int node, int par, int diam)
{
    if (diam > maxDiam)
    {
        maxDiam = diam;
        start = node;
    }
    for (int n1 : adjL[node])
    {
        if (n1 != par && isPho[n1])
        {
            getDiam(n1, node, diam + 1);
        }
    }
}