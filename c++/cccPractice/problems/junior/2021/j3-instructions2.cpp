#include <stdio.h>
#include <string>

int main()
{
    int i;
    int s;
    std::string dir;
    while (scanf("%d", &i), i != 99999)
    {
        s = i / 10000 + i / 1000 % 10;
        if (s % 2 == 1)
        {
            dir = "left";
        }
        else if (s % 2 == 0 && s != 0)
        {
            dir = "right";
        }
        printf("%s %d\n", dir.c_str(), i % 1000);
    }
}