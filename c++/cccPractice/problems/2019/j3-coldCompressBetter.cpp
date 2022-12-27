#include <string>
#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);

    int lines;
    int occurrences = 1;
    std::string input;
    std::cin >> lines;

    for (int i = 0; i < lines; i++)
    {
        std::cin >> input;
        for (int j = 0; j < (int)input.length(); j++)
        {
            if (input[j] == input[j + 1])
            {
                occurrences += 1;
            }
            else
            {
                std::cout << occurrences << " " << input[j] << " ";
                occurrences = 1;
            }
        }
        std::cout << '\n';
    }
}