#include <iostream>

int numCoins, coin;

int main()
{
    std::ios_base::sync_with_stdio(false);

    do
    {
        std::cin >> numCoins;

        if (numCoins == 0)
        {
            return 0;
        }

        int *stack1 = new int[numCoins];
        int *stack2 = new int[numCoins];
        int *stack3 = new int[numCoins];
        int *stack4 = new int[numCoins];

        for (int i = 1; i <= numCoins; i++)
        {
            std::cin >> coin;
            if (i == 1)
            {
                stack1[0] = coin;
            }
            if (i == 2)
            {
                stack2[0] = coin;
            }
            if (i == 3)
            {
                stack3[0] = coin;
            }
            if (i == 4)
            {
                stack4[0] = coin;
            }
        }
    } while (numCoins != 0);
}