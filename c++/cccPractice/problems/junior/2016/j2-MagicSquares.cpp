#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);

    int rowSum1 = 0, rowSum2 = 0;
    int colSum1 = 0, colSum2 = 0, colSum3 = 0, colSum4 = 0;
    int n;
    bool isMagic = true;
    for (int i = 0; i < 4; i++)
    {

        for (int j = 0; j < 4; j++)
        {
            std::cin >> n;
            if (j == 0)
            {
                colSum1 += n;
            }
            if (j == 1)
            {
                colSum2 += n;
            }
            if (j == 2)
            {
                colSum3 += n;
            }
            if (j == 3)
            {
                colSum4 += n;
            }

            if (i % 2 == 0)
            {
                rowSum1 += n;
            }
            else
            {
                rowSum2 += n;
            }
        }
        if (i >= 1)
        {
            if (rowSum1 == rowSum2)
            {
                if (i % 2 == 0)
                {
                    rowSum2 = 0;
                }
                else
                {
                    rowSum1 = 0;
                }
            }
            else
            {
                isMagic = false;
                break;
            }
        }
    }
    if (colSum1 == colSum2 && colSum2 == colSum3 && colSum3 == colSum4)
    {
    }
    else
    {
        isMagic = false;
    }
    std::cout << (isMagic ? "magic" : "not magic") << '\n';
}