#include <iostream>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

bool checkTunnel(map<int, vector<int>> &coords, int &i, int &dist, int &currentX, int &currentY, bool &isDanger);

int main()
{
    std::ios_base::sync_with_stdio(false);

    bool isDanger = false;
    char dir = 'a';
    int dist;
    int currentX = -1;
    int currentY = -5;
    map<int, vector<int>> coords;
    coords[-1].push_back(-5);
    coords[-1].push_back(-6);
    coords[-1].push_back(-7);

    coords[0].push_back(-1);
    coords[0].push_back(-2);
    coords[0].push_back(-3);
    coords[0].push_back(-7);

    coords[1].push_back(-3);
    coords[1].push_back(-7);

    coords[2].push_back(-3);
    coords[2].push_back(-7);

    coords[3].push_back(-3);
    coords[3].push_back(-4);
    coords[3].push_back(-5);
    coords[3].push_back(-7);

    coords[4].push_back(-5);
    coords[4].push_back(-7);

    coords[5].push_back(-3);
    coords[5].push_back(-4);
    coords[5].push_back(-5);
    coords[5].push_back(-7);

    coords[6].push_back(-3);
    coords[6].push_back(-7);

    coords[7].push_back(-3);
    coords[7].push_back(-4);
    coords[7].push_back(-5);
    coords[7].push_back(-6);
    coords[7].push_back(-7);

    do
    {
        cin >> dir >> dist;
        if (dir == 'q')
        {
            return 0;
        }
        for (int i = 0; i < dist; i++)
        {
            if (dir == 'l')
            {
                currentX -= 1;
                if (checkTunnel(coords, i, dist, currentX, currentY, isDanger))
                {
                    return 0;
                }
            }
            else if (dir == 'r')
            {
                currentX += 1;
                if (checkTunnel(coords, i, dist, currentX, currentY, isDanger))
                {
                    return 0;
                }
            }
            else if (dir == 'u')
            {
                currentY += 1;
                if (checkTunnel(coords, i, dist, currentX, currentY, isDanger))
                {
                    return 0;
                }
            }
            else
            {
                currentY -= 1;
                if (checkTunnel(coords, i, dist, currentX, currentY, isDanger))
                {
                    return 0;
                }
            }
        }
    } while (dir != 'q');
}

bool checkTunnel(map<int, vector<int>> &coords, int &i, int &dist, int &currentX, int &currentY, bool &isDanger)
{
    if (find(coords[currentX].begin(), coords[currentX].end(), currentY) != coords[currentX].end())
    {
        isDanger = true;
    }
    if (isDanger && i == dist - 1)
    {
        cout << currentX << " " << currentY << " DANGER" << '\n';
        return true;
    }
    else
    {
        coords[currentX].push_back(currentY);
        if (i == dist - 1)
        {
            cout << currentX << " " << currentY << " safe" << '\n';
            return false;
        }
    }
    return false;
}