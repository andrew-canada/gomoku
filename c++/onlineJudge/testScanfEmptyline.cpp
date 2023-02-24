#include <cstdio>
#include <cstring>

char str[100];

int main()
{
    printf("Enter string:\n");

    // Read input from standard input
    int num = scanf("%99[^\n]%*c", str);

    // Test if the input is an empty line
    if (num == EOF || (num == 0 && std::strlen(str) == 0))
    {
        printf("You entered an empty line.\n");
    }
    else
    {
        printf("You entered: %s", str);
    }

    return 0;
}
