#include <string>
#include <iostream>

int main()
{
    std::ios_base::sync_with_stdio(false);

    int lines, occurrences;
    std::string input, msg;
    std::cin >> lines;

    for (int i = 0; i < lines; i++)
    {
        std::cin >> input;
        for (int j = 0; j < (int)input.length(); j++)
        {
            occurrences = 1;
            while (input[j] == input[j + 1])
            {
                occurrences += 1;
                j += 1;
            }
            msg += std::to_string(occurrences);
            msg += ' ';
            msg += input[j];
            msg += ' ';
        }
        std::cout << msg << '\n';
        msg.clear();
    }
}