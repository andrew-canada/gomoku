#include <stdio.h>
#include <string>

bool isDistinct(int &year)
{
    std::string yearStr = std::to_string(year);

    for (int i = 0; i < yearStr.size(); i++)
    {
        for (int j = i + 1; j < yearStr.size(); j++)
        {
            if (yearStr[i] == yearStr[j])
            {
                return false;
            }
        }
    }
    return true;
}

int main()
{
    int year;
    scanf("%d", &year);
    while (!isDistinct(++year))
    {
    }
    printf("%d", year);
}