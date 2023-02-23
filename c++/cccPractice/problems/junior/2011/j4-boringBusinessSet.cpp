#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

bool checkTunnel(unordered_set<string> &coords, string coord, int &i, int &dist, int &currentX, int &currentY, bool &isDanger);

unordered_set<string> coords =
    {
        ("-1 -5"), ("-1 -6"), ("-1 -7"),
        ("0 -1"), ("0 -2"), ("0 -3"), ("0 -7"),
        ("1 -3"), ("1 -7"),

        ("2 -3"),
        ("2 -7"),

        ("3 -3"),
        ("3 -4"),
        ("3 -5"),
        ("3 -7"),

        ("4 -5"),
        ("4 -7"),

        ("5 -3"),
        ("5 -4"),
        ("5 -5"),
        ("5 -7"),

        ("6 -3"),
        ("6 -7"),

        ("7 -3"),
        ("7 -4"),
        ("7 -5"),
        ("7 -6"),
        ("7 -7")};

int main()
{
    std::ios_base::sync_with_stdio(false);

    string coord = "";
    char dir = 'a';
    int dist;
    int currentX = -1;
    int currentY = -5;
    bool isDanger = false;

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
                if (checkTunnel(coords, coord, i, dist, currentX, currentY, isDanger))
                {
                    return 0;
                }
            }
            else if (dir == 'r')
            {
                currentX += 1;
                if (checkTunnel(coords, coord, i, dist, currentX, currentY, isDanger))
                {
                    return 0;
                }
            }
            else if (dir == 'u')
            {
                currentY += 1;
                if (checkTunnel(coords, coord, i, dist, currentX, currentY, isDanger))
                {
                    return 0;
                }
            }
            else
            {
                currentY -= 1;
                if (checkTunnel(coords, coord, i, dist, currentX, currentY, isDanger))
                {
                    return 0;
                }
            }
        }
    } while (dir != 'q');
}

bool checkTunnel(unordered_set<string> &coords, string coord, int &i, int &dist, int &currentX, int &currentY, bool &isDanger)
{
    coord += to_string(currentX);
    coord += " ";
    coord += to_string(currentY);
    if (!coords.insert(coord).second)
    {
        isDanger = true;
    }
    if (isDanger && i == dist - 1)
    {
        cout << coord << " DANGER" << '\n';
        return true;
    }
    else
    {
        if (i == dist - 1)
        {
            cout << coord << " safe" << '\n';
            return false;
        }
    }
    return false;
}