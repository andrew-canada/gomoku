#include <stdio.h>
#include <vector>

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

using namespace std;

int g, p;
int numPlanes;
vector<int> gates;

int getMaxSpot(int plane);

int main()
{
    int curPlane = 0, curSpot = 0;

    scanf("%d%d", &g, &p);
    REP(i, 1, g)
    {
        gates.push_back(i);
    }
    REP(i, 1, p)
    {
        scanf("%d", &curPlane);
        curSpot = getMaxSpot(curPlane);
        if (curSpot == -1)
        {
            break;
        }
        else
        {
            gates.erase(gates.begin() + curSpot);
            numPlanes++;
        }
    }
    printf("%d", numPlanes);
}

int getMaxSpot(int plane)
{
    int gate = -1;
    int mid = 0, low = 0, high = gates.size() - 1;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (gates[mid] == plane)
        {
            return mid;
        }
        else if (gates[mid] < plane)
        {
            gate = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return gate;
}