#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);

    int length1 = 1, length2 = 2;

    bool isEnter1 = true, isEnter2 = true;

    std::string input;
    std::vector<int> lengths;

    std::cin >> input;

    if (input.size() == 1)
    {
        std::cout << 1;
        return 0;
    }
    else if (input.size() == 2)
    {
        if (input[0] == input[1])
        {
            std::cout << 2;
            return 0;
        }
        else
        {
            std::cout << 1;
            return 0;
        }
    }

    for (int i = 0; i < input.size(); i++)
    {
        for (int j = 1; j < input.size(); j++)
        {
            // odd : move out from single char
            if (i - j >= 0 && i + j < input.size())
            {
                if (input[i - j] == input[i + j] && isEnter1)
                {
                    length1 += 2;
                }
                else
                {
                    isEnter1 = false;
                }
            }

            // even : move out from char and char+1
            if (i - j >= 0 && i + j + 1 < input.size())
            {
                if (input[i - j] == input[i + j + 1] && input[i] == input[i + 1] && isEnter2)
                {
                    length2 += 2;
                }
                else
                {
                    isEnter2 = false;
                }
            }
            else
            {
                j = 1;
                break;
            }
        }
        lengths.push_back(length1);
        lengths.push_back(length2);
        length1 = 1;
        length2 = 2;
        isEnter1 = true;
        isEnter2 = true;
    }

    std::cout << *max_element(lengths.begin(), lengths.end());
}