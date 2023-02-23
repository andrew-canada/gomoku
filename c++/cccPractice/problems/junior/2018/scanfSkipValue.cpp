#include <stdio.h>

int main()
{
    // scanf reads a character but doesn't save it.
    // Doesn't do anything. Can use when reading unnecessary values.
    char c = scanf("%*c");
    printf("%c", c);
}