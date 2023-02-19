#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int sameCount = 0;
    int numCoins;
    stack<int> *coinStacks;
    int tempCoinNum;

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

        coinStacks = new stack<int>[numCoins];

        for (int i = 0; i < numCoins; i++)
        {
            cin >> tempCoinNum;
            coinStacks[i].push(tempCoinNum);
            if (i > 0)
            {
                if (coinStacks[i].top() > coinStacks[i - 1].top())
                {
                    sameCount += 1;
                }
            }
        }

        if (sameCount == numCoins - 1)
        {
            cout << 0;
        }

    } while (true);
}