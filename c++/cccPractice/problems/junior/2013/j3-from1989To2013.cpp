#include <stdio.h>
#include <string>
#include <algorithm>

int main()
{
    int yearNum;
    scanf("%d", &yearNum);

    yearNum += 1;

    std::string yearStr = std::to_string(yearNum);

    for (int i = 0; i < 5; i++)
    {
        if (std::count(yearStr.begin(), yearStr.end(), yearStr[i]) > 1)
        {
            i = 0;
            yearNum += 1;
            yearStr = std::to_string(yearNum);
        }
        else if (i == yearStr.length() - 1)
        {
            printf("%d", yearNum);
            return 0;
        }
    }
}