#include <iostream>
#include <algorithm>

using namespace std;

int coinStacks[5][6] = {0};

int main()
{
    ios_base::sync_with_stdio(false);

    int sameCount = 0;
    int numCoins;
    int moveCount = 0;
    bool isSorted = true;
    int smallest = 9;
    int smaller;
    int locationOfSmallest;

    do
    {
        cin >> numCoins;
        if (numCoins == 0)
        {
            return 0;
        }
        if (numCoins == 1)
        {
            cout << 1;
        }

        // check if initially sorted
        for (int i = 0; i < numCoins; i++)
        {
            cin >> coinStacks[i][0];
            coinStacks[i][5] = 1;

            if (i > 0)
            {
                if (coinStacks[i][0] > coinStacks[i - 1][0])
                {
                    sameCount += 1;
                }
            }
        }

        if (sameCount == numCoins - 1)
        {
            cout << 0;
        }
        else if (numCoins == 2)
        {
            cout << "IMPOSSIBLE";
        }

        do
        {
            // find smallest
            for (int i = 0; i < numCoins - 1; i++)
            {
                smaller = min(coinStacks[i][coinStacks[i][5] - 1], coinStacks[i + 1][coinStacks[i + 1][5] - 1]);
                if (smallest > smaller)
                {
                    smallest = smaller;
                    if (coinStacks[i][coinStacks[i][5] - 1] > coinStacks[i + 1][coinStacks[i + 1][5] - 1])
                    {
                        locationOfSmallest = i + 1;
                    }
                    else
                    {
                        locationOfSmallest = i;
                    }
                }
            }

            // move coin
            if (coinStacks[locationOfSmallest - 1][coinStacks[locationOfSmallest - 1][5] - 1] > smallest)
            {
                coinStacks[locationOfSmallest][5] -= 1;
                coinStacks[locationOfSmallest - 1][5] += 1;
                coinStacks[locationOfSmallest - 1][coinStacks[locationOfSmallest - 1][5]] = smallest;
            }

            // shift coins back
            for (int i = 0; i < numCoins; i++)
            {
                if (coinStacks[i][5] == 0)
                {
                    for (int j = i - 1; j >= 0; j--)
                    {
                        if (coinStacks[j][5] == 1)
                        {
                            coinStacks[j][5] -= 1;
                            coinStacks[j + 1][5] += 1;
                            coinStacks[j + 1][0] = coinStacks[j][0];
                        }
                    }
                }
            }

            // check if sorted
            for (int i = 0; i < numCoins; i++)
            {
                if (coinStacks[i][0] != i + 1)
                {
                    isSorted = false;
                }
            }
            moveCount += 1;

            if (isSorted)
            {
                cout << moveCount;
                break;
            }
        } while (true);

        sameCount = 0;
        moveCount = 0;
        isSorted = true;
        smallest = 9;

    } while (true);
}