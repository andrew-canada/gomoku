// circular street of circumference 1,000,000
// h houses [1, 1000]
// ccw arc length from north is house address (top is 0)
// k hoses [1, 1000] (must connect to all houses)
// all hose are same length
// minimize length of hose such that all houses are connected to a hose

#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

vector<int> house;

bool ca(int len, int h, int k);

int main()
{
    int h, k;
    int ch;
    scanf("%d", &h);
    REP(i, 0, h)
    {
        scanf("%d", &ch);
        house.push_back(ch);
    }
    scanf("%d", &k);
    if (k > h)
    {
        printf("0");
        return 0;
    }
    int low = 0, high = 1000000;
    int mid;
    int len;
    sort(house.begin(), house.end());
    while (low <= high)
    {
        mid = (low + high) / 2;
        if (ca(mid, h, k))
        {
            len = mid;
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    printf("%d", len);
}

bool ca(int len, int h, int k)
{
    int pos;
    int nh;
    bool ac;
    REP(i, 0, h)
    {
        pos = house[i] + len;
        nh = k - 1;
        ac = true;
        REP(j, i, h)
        {
            if (house[j] - pos > len)
            {
                if (nh > 0)
                {
                    pos = house[j] + len;
                    nh--;
                }
                else
                {
                    ac = false;
                    break;
                }
            }
        }
        if (!ac)
        {
            continue;
        }
        REP(j, 0, i)
        {
            if (1000000 + house[j] - pos > len)
            {
                if (nh > 0)
                {
                    pos = 1000000 + house[j] + len;
                    nh--;
                }
                else
                {
                    ac = false;
                    break;
                }
            }
        }
        if (!ac)
        {
            continue;
        }
        return true;
    }
    return false;
}