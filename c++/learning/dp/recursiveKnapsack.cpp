#include <stdio.h>

int getNumCombos(int number)
{
    if (number < 0)
    {
        return 0;
    }
    else if (number == 0)
    {
        return 1;
    }
    return getNumCombos(number - 1) + getNumCombos(number - 3) + getNumCombos(number - 5);
}

int main()
{
    printf("%d\n", getNumCombos(1));
    printf("%d\n", getNumCombos(5));
    printf("%d\n", getNumCombos(8));
}
