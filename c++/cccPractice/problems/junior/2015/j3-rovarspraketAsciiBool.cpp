#include <iostream>
#include <string>

bool isVowel(char c)
{
    if (c == 97 || c == 101 || c == 105 || c == 111 || c == 117)
    {
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    std::ios_base::sync_with_stdio(false);
    std::string input;
    std::cin >> input;

    for (int i = 0; i < input.length(); i++)
    {
        std::cout << input[i];
        if (!isVowel(input[i]))
        {
            for (int j = 1; j < 10; j++)
            {
                if (isVowel(input[i] - j))
                {
                    std::cout << char(input[i] - j);
                    break;
                }
                else if (isVowel(input[i] + j))
                {
                    std::cout << char(input[i] + j);
                    break;
                }
            }

            if (input[i] == 122)
            {
                std::cout << input[i];
            }
            else if (isVowel(input[i] + 1))
            {
                std::cout << char(input[i] + 2);
            }
            else
            {
                std::cout << char(input[i] + 1);
            }
        }
    }
}