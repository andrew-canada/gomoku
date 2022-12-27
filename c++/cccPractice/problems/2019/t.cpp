#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    std::vector<char> input({'a', 'b', 'c'});

    std::string s;
    std::transform(input.begin(), input.end(), std::back_inserter(s),
                   [](char c)
                   {
                       return c;
                   });

    std::cout << s;

    return 0;
}