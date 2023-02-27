#include <iostream>
#include <vector>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b - 1); i++)

vector<int> pSet(1000);

void init(int setSize)
{
    pSet.resize(setSize);
    REP(i, 0, setSize) { pSet[i] = i; }
}

int findSet(int setNum)
{
    if (pSet[setNum] != setNum)
    {
        pSet[setNum] = findSet(pSet[setNum]); // for path compression
    }
    return pSet[setNum];
}

void unionSet(int set1, int set2)
{
    pSet[findSet(set1)] = findSet(set2);
}

bool isSameSet(int set1, int set2)
{
    return (findSet(set1) == findSet(set2));
}

int main()
{
    init(5);
    cout << findSet(1) << '\n';
    unionSet(1, 2);
    cout << findSet(1) << '\n';
    cout << isSameSet(1, 2) << '\n';
    cout << isSameSet(1, 3) << '\n';
}