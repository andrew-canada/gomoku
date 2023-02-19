#include <stdio.h>
#include <string>
#include <iterator>
#include <algorithm>
#include <vector>
#include <iostream>

int main()
{
    int lines;
    scanf("%d", &lines);
    int *repetitions = new int[lines];
    char *character = new char[lines];

    for (int i = 0; i < lines; i++)
    {
        scanf("%d %c", &repetitions[i], &character[i]);
    }

    for (int i = 0; i < lines; i++)
    {
        std::vector<char> v;
        v.insert(v.begin(), repetitions[i], character[i]);
        std::string s;
        std::transform(v.begin(), v.end(), std::back_inserter(s), [](char c)
                       { return c; });
        std::cout << s << "\n";
    }
}