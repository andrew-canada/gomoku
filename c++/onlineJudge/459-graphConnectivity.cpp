#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
#include <string>
#include <utility>
#include <set>

using namespace std;

// #define LOCAL
#define REP(i, a, b) for (int i = int(a); i <= int(b - 1); i++)

typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vii edgeList;
vi ufdSet;
set<int> parents;
string edge;
int cases;
char maxNode;
bool isFirst = true;

void initSet(int s);
int findSet(int n);
bool isSameSet(int a, int b);
void unionSet(int a, int b);

int main()
{
#ifdef LOCAL
    freopen("459.in", "r", stdin);
    freopen("459.out", "w", stdout);
#endif
    scanf("%d", &cases);
    while (cases--)
    {
        if (isFirst)
        {
            isFirst = false;
        }
        else
        {
            printf("\n");
        }
        scanf(" %c", &maxNode);
        initSet(maxNode + 1);

        int i = 0;
        getline(cin, edge);
        while (getline(cin, edge), !edge.empty())
        {
            edgeList.push_back({edge[0], edge[1]});
            i++;
        }

        for (auto &[nd1, nd2] : edgeList)
        {
            if (!isSameSet(nd1, nd2))
            {
                unionSet(nd1, nd2);
            }
        }

        for (int i = 'A'; i <= maxNode; i++)
        {
            parents.insert(findSet(i));
        }

        printf("%d\n", parents.size());

        edgeList.clear();
        parents.clear();
    }
}

void initSet(int n)
{
    ufdSet.resize(n);
    REP(i, 0, n) { ufdSet[i] = i; }
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
