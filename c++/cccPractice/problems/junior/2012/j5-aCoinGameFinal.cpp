#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

void solve();
void moveCoins(int *coins, int index1, int index2);
bool isOrdered(int *coins);
bool isVisited(int *coins);

int numCoins;
stack<int *> coinStacks;
vector<string> visitedPositions;

int main()
{
    do
    {
        cin >> numCoins;
        if (numCoins == 0)
        {
            break;
        }
        solve();
        numCoins == 0;
        visitedPositions.clear();
        for (int i = 0; i < coinStacks.size(); i++)
        {
            coinStacks.pop();
        }
    } while (true);
}

void solve()
{
    int *input = new int[numCoins + 1];
    input[numCoins] = 0;
    for (int i = 0; i < numCoins; i++)
    {
        cin >> input[i];
    }

    coinStacks.push(input);

    int *currentArrangement = new int[numCoins + 1];
    currentArrangement[numCoins] = 0;

    while (!coinStacks.empty())
    {
        currentArrangement = coinStacks.top();
        coinStacks.pop();

        if (isOrdered(currentArrangement))
        {
            cout << currentArrangement[numCoins] << '\n';
            return;
        }

        for (int i = 0; i < numCoins - 1; i++)
        {
            if (currentArrangement[i] != 0 || currentArrangement[i + 1] != 0)
            {
                int *nextPos = new int[numCoins + 1];
                for (int j = 0; j <= numCoins; j++)
                {
                    nextPos[j] = currentArrangement[j];
                }
                moveCoins(nextPos, i, i + 1);
                if (!isVisited(nextPos))
                {
                    nextPos[numCoins] += 1;
                    coinStacks.push(nextPos);
                    for (int i = 0; i <= numCoins; i++)
                    {
                        cout << nextPos[i] << " ";
                    }
                    cout << '\n';
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << '\n';
}
void moveCoins(int *coins, int index1, int index2)
{
    int coin1 = coins[index1];
    int coin2 = coins[index2];

    if (coin1 == 0)
    {
        coin1 = coin2 % 10;
        coin2 = coin2 / 10;
    }
    else if (coin2 == 0)
    {
        coin2 = coin1 % 10;
        coin1 = coin1 / 10;
    }
    else if (coin1 % 10 > coin2 % 10)
    {
        coin1 = coin1 * 10 + coin2 % 10;
        coin2 = coin2 / 10;
    }
    else
    {
        coin2 = coin2 * 10 + coin1 % 10;
        coin1 = coin1 / 10;
    }

    coins[index1] = coin1;
    coins[index2] = coin2;
}
bool isOrdered(int *coins)
{
    for (int i = 0; i < numCoins; i++)
    {
        if (coins[i] != i + 1)
        {
            return false;
        }
    }
    return true;

    // lambda captures are immutable by default
}

bool isVisited(int *coins)
{
    string position;
    for (int i = 0; i < numCoins; i++)
    {
        position += coins[i] + " ";
    }
    if (find(begin(visitedPositions), end(visitedPositions), position) != visitedPositions.end())
    {
        return true;
    }
    else
    {
        visitedPositions.push_back(position);
        return false;
    }
}