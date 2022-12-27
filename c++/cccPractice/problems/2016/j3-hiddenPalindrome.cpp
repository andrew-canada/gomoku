#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

int main()
{
    std::ios_base::sync_with_stdio(false);

    int length = 0;
    std::string input;
    std::string reverse;
    std::vector<int> lengths;

    std::cin >> input;

    int j = 0;
    for (int i = input.size() - 1; i >= 0; i--)
    {
        reverse[j] = input[i];
        j++;
    }

    for (int i = 0; i < input.size(); i++)
    {
        if (input[i] == reverse[i])
        {
            length += 1;
            if (i == input.size() - 1)
            {
                lengths.push_back(length);
            }
        }
        else
        {
            lengths.push_back(length);
            length = 0;
            i -= length;
        }
    }

    std::cout << *max_element(lengths.begin(), lengths.end());
}