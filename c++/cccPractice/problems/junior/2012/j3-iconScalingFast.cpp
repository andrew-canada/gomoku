#include <stdio.h>

int main()
{
    char diagram[3][3] = {{'*', 'x', '*'}, {' ', 'x', 'x'}, {'*', ' ', '*'}};

    int scaleFactor;
    scanf("%d", &scaleFactor);

    for (int i = 0; i < scaleFactor * 3; i++)
    {
        for (int j = 0; j < scaleFactor * 3; j++)
        {
            printf("%c", diagram[i / scaleFactor][j / scaleFactor]);
        }
        fputs("\n", stdout);
    }
}