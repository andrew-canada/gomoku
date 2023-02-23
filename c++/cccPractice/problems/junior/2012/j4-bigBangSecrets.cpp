#include <iostream>
#include <string>

int main()
{
    std::ios_base::sync_with_stdio(false);

    int shiftBase, shiftFactor;
    std::string input;

    std::cin >> shiftBase >> input;

    for (int i = 0; i < input.length(); i++)
    {
        shiftFactor = 3 * (i + 1) + shiftBase;

        if (input[i] - shiftFactor < 65)
        {
            std::cout << char(90 - (shiftFactor - (input[i] - 65)) + 1);
        }
        else
        {
            std::cout << char(input[i] - shiftFactor);
        }
    }
}