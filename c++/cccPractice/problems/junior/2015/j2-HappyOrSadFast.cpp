#include <iostream>
#include <string>

int main()
{
    std::ios_base::sync_with_stdio(false);

    int happyCount = 0, sadCount = 0;
    std::string input;

    getline(std::cin, input);
    for (int i = 0; i < (int)input.length() - 2; i++)
    {
        if (input[i] == ':' && input[i + 1] == '-')
        {
            if (input[i + 2] == ')')
            {
                happyCount++;
            }
            if (input[i + 2] == '(')
            {
                sadCount++;
            }
        }
    }

    if (happyCount == 0 && sadCount == 0)
    {
        std::cout << "none";
    }
    else if (happyCount == sadCount)
    {
        std::cout << "unsure";
    }
    else if (happyCount > sadCount)
    {
        std::cout << "happy";
    }
    else
    {
        std::cout << "sad";
    }
}