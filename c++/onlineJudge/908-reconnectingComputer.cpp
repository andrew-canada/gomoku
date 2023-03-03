#include <stdio.h>
#include <tuple>
#include <vector>
#include <algorithm>

using namespace std;

// #define LOCAL
#define REP(i, a, b) for (int i = int(a); i <= int(b - 1); i++)

typedef tuple<int, int, int> iii;
typedef vector<int> vi;

vector<iii> edgeList;
vi ufdSet;
int nodes;
int extra;
int origNodes;
int n1, n2, w;

void initSet(int s);
int findSet(int n);
bool isSameSet(int a, int b);
void unionSet(int a, int b);

int main()
{
#ifdef LOCAL
    freopen("908-2.in", "r", stdin);
    freopen("908.out", "w", stdout);
#endif
    while (true)
    {
        int totWeight = 0;
        int numTaken = 1;
        int orig = 0;
        edgeList.clear();
        ufdSet.clear();

        if (scanf(" %d", &nodes) == EOF)
        {
            break;
        }
        REP(i, 0, nodes - 1)
        {
            scanf("%*d %*d %d", &w);
            orig += w;
        }
        printf("%d\n", orig);

        scanf("%d", &extra);
        REP(i, 0, extra)
        {
            scanf("%d %d %d", &n1, &n2, &w);
            edgeList.push_back({w, n1, n2});
        }

        scanf("%d", &origNodes);
        REP(i, 0, origNodes)
        {
            scanf("%d %d %d", &n1, &n2, &w);
            edgeList.push_back({w, n1, n2});
        }

        sort(edgeList.begin(), edgeList.end());
        int edges = extra + origNodes;
        initSet(nodes + 1);
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

        printf("%d\n\n", totWeight);
    }
}

void initSet(int s)
{
    ufdSet.resize(s);
    REP(i, 0, s) { ufdSet[i] = i; }
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
    if (!isSameSet(a, b))
    {
        int x = findSet(a);
        int y = findSet(b);
        ufdSet[x] = y;
    }
}