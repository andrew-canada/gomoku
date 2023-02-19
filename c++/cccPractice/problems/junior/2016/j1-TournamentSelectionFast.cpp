#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);

    char winOrLose;
    int winCount = 0;
    for (int i = 1; i <= 6; i++)
    {
        std::cin >> winOrLose;
        if (winOrLose == 'W')
        {
            winCount += 1;
        }
    }

    if (winCount >= 5)
    {
        std::cout << 1;
    }
    else if (winCount >= 3)
    {
        std::cout << 2;
    }
    else if (winCount >= 1)
    {
        std::cout << 3;
    }
    else
    {
        std::cout << -1;
    }
}