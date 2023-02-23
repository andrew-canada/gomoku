#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

void solve();
void moveCoins(vector<int> &coins, int index1, int index2);
bool isOrdered(vector<int> &coins);
bool isVisited(vector<int> coins);

int numCoins;
stack<vector<int>> coinStacks;
vector<vector<int>> visitedPositions;

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
    vector<int> input(numCoins + 1, 0);
    int tempNum;
    for (int i = 0; i < numCoins; i++)
    {
        cin >> tempNum;
        input.at(i) = tempNum;
    }
    // for_each(begin(input), end(input), [](int n)
    //          { cout << n; });
    coinStacks.push(input);

    vector<int> currentArrangement(numCoins + 1, 0);

    while (!coinStacks.empty())
    {
        currentArrangement = coinStacks.top();
        coinStacks.pop();

        if (isOrdered(currentArrangement))
        {
            cout << currentArrangement.back() << '\n';
            return;
        }

        for (int i = 0; i < numCoins - 1; i++)
        {
            if (currentArrangement.at(i) != 0 || currentArrangement.at(i + 1) != 0)
            {
                vector<int> nextPos = currentArrangement;
                moveCoins(nextPos, i, i + 1);
                if (!isVisited(nextPos))
                {
                    nextPos.back() += 1;
                    coinStacks.push(nextPos);
                    for_each(begin(nextPos),
                             end(nextPos),
                             [](int n)
                             {
                                 cout << n << " ";
                             });
                    cout << '\n';
                }
            }
        }
    }
    cout << "IMPOSSIBLE" << '\n';
}
void moveCoins(vector<int> &coins, int index1, int index2)
{
    int coin1 = coins.at(index1);
    int coin2 = coins.at(index2);

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

    coins.at(index1) = coin1;
    coins.at(index2) = coin2;
}
bool isOrdered(vector<int> &coins)
{
    for (int i = 0; i < numCoins; i++)
    {
        if (coins.at(i) != i + 1)
        {
            return false;
        }
    }
    return true;

    // lambda captures are immutable by default
}

bool isVisited(vector<int> coins)
{
    coins.erase(end(coins) - 1);
    if (find(begin(visitedPositions), end(visitedPositions), coins) != visitedPositions.end())
    {
        return true;
    }
    else
    {
        visitedPositions.push_back(coins);
        return false;
    }
}