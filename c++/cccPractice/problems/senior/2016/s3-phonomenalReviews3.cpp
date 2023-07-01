#include <stdio.h>
#include <vector>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

int n, m;
vector<int> adjL[100005];
bool isPho[100005];
int d;
int start;

void markPho(int node, int par);
void getDiam(int node, int par, int diam);

int main()
{
    scanf("%d%d", &n, &m);
    int ind;
    REP(i, 0, m)
    {
        scanf("%d", &ind);
        isPho[ind] = true;
    }

    int n1, n2;
    REP(i, 0, n - 1)
    {
        scanf("%d%d", &n1, &n2);
        adjL[n1].push_back(n2);
        adjL[n2].push_back(n1);
    }

    markPho(ind, -1);
    getDiam(ind, -1, 0);
    getDiam(start, -1, 0);
    int numPho = 0;
    for (bool b : isPho)
    {
        if (b)
        {
            numPho++;
        }
    }
    printf("%d", 2 * (numPho - 1) - d);
}

void markPho(int node, int par)
{
    for (int v : adjL[node])
    {
        if (v != par)
        {
            markPho(v, node);
            if (isPho[v])
            {
                isPho[node] = true;
            }
        }
    }
}

void getDiam(int node, int par, int diam)
{
    if (diam > d)
    {
        d = diam;
        start = node;
    }
    for (int v : adjL[node])
    {
        if (v != par && isPho[v])
        {
            getDiam(v, node, diam + 1);
        }
    }
}
