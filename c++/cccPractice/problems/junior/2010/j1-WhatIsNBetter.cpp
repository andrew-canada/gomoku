#include <stdio.h>

int main()
{
    char n = getchar();
    switch (n)
    {
    case '1':
    case '9':
        puts("1");
        break;
    case '2':
    case '3':
    case '7':
    case '8':
        puts("2");
        break;
    case '4':
    case '5':
    case '6':
        puts("3");
        break;
    default:
        puts("1");
        break;
    }
}