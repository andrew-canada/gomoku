#include <stdio.h>

int comboArray[100];

int dpGetNumCombos(int number)
{
    if (number < 0)
    {
        return 0;
    }
    else if (number == 0)
    {
        return 1;
    }
    if (comboArray[number] == 0)
    {
        return dpGetNumCombos(number - 1) + dpGetNumCombos(number - 3) + dpGetNumCombos(number - 5);
    }
    else
    {
        return comboArray[number];
    }
}

int main()
{
    printf("%d\n", dpGetNumCombos(1));
    printf("%d\n", dpGetNumCombos(5));
    printf("%d\n", dpGetNumCombos(8));
}
