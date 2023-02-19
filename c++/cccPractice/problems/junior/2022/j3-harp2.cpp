#include <stdio.h>

char input[521];

int main()
{
    scanf("%s", &input);
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (input[i] == '+')
        {
            printf(" tighten ");
        }
        else if (input[i] == '-')
        {
            printf(" loosen ");
        }
        else if (input[i] <= '9' && input[i + 1] > '9')
        {
            printf("%c\n", input[i]);
        }
        else
        {
            printf("%c", input[i]);
        }
    }
}