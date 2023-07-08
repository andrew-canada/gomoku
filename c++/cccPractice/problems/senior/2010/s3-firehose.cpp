#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

int h, hyd;
int minLen;
vector<int> houses;

bool connectsAll(int hoseLen);

int main()
{
    int curHouse;
    scanf("%d", &h);
    REP(i, 0, h)
    {
        scanf("%d", &curHouse);
        houses.push_back(curHouse);
    }
    scanf("%d", &hyd);

    if (hyd >= h)
    {
        printf("%d", 0);
        return 0;
    }
    sort(houses.begin(), houses.end());
    int low = 0, high = 1000000;
    int mid;
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (connectsAll(mid))
        {
            high = mid - 1;
            minLen = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    printf("%d", minLen);
}

bool connectsAll(int hoseLen)
{
    REP(i, 0, h)
    {
        int hoseEnd = houses[i] + hoseLen;
        int remHyd = hyd - 1;
        REP(j, i, h)
        {
            if (houses[j] - hoseEnd > hoseLen)
            {
                if (remHyd > 0)
                {
                    remHyd--;
                    hoseEnd = houses[j] + hoseLen;
                }
                else
                {
                    return false;
                }
            }
        }
        return true;
    }
    return false;
}