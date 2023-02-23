#include <stdio.h>
#include <string>

int main()
{
    char input[540];
    scanf("%s", input);
    for (int i = 0; input[i] != '\0'; i++)
    {
        if (isalpha(input[i]))
        {
            printf("%c", input[i]);
        }
        else if (input[i] == '+')
        {
            printf(" tighten ");
        }
        else if (input[i] == '-')
        {
            printf(" loosen ");
        }
        else if (isdigit(input[i]))
        {
            printf("%c", input[i]);
            if (isalpha(input[i + 1]))
            {
                printf("\n");
            }
        }
    }
}