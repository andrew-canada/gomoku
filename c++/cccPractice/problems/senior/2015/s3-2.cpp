#include <stdio.h>
#include <vector>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

int g, p;
vector<int> gates;
int maxGate, numPlanes;
int curPlane;

int main()
{
    scanf("%d%d", &g, &p);
    REP(i, 1, g)
    {
        gates.push_back(i);
    }
    int low, high, mid;
    REP(i, 0, p - 1)
    {
        scanf("%d", &curPlane);
        low = 0, high = gates.size() - 1;
        maxGate = -1;
        while (low <= high)
        {
            mid = (low + high) / 2;
            if (gates[mid] == curPlane)
            {
                maxGate = mid;
                break;
            }
            else if (gates[mid] < curPlane)
            {
                low = mid + 1;
                maxGate = mid;
            }
            else
            {
                high = mid - 1;
            }
        }
        if (maxGate == -1)
        {
            break;
        }
        else
        {
            gates.erase(gates.begin() + maxGate);
            numPlanes++;
        }
    }
    printf("%d", numPlanes);
}