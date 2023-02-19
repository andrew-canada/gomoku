#include <stdio.h>

int main()
{
    int numCars;
    int occupied = 0;
    // char day2Car;

    scanf("%d", &numCars);

    char *day1 = new char[numCars];

    for (int i = 0; i <= numCars; i++)
    {
        // if (i == 0)
        // {
        //     puts("first input");
        // }
        // if (i == 1)
        // {
        //     puts("second input");
        // }
        day1[i] = getchar();
        // printf("%c", day1[i]);
    }

    for (int i = 0; i <= numCars; i++)
    {
        if (day1[i] == getchar() && day1[i] == 'C')
        {
            occupied += 1;
        }
    }

    printf("%d", occupied);
}