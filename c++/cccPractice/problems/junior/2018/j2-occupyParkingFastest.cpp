#include <stdio.h>

int main()
{
    int numCars;
    int occupied = 0;
    char day1[100], day2[100];

    scanf("%d", &numCars);
    scanf("%s%s", &day1, &day2);

    for (int i = 0; i <= numCars; i++)
    {
        if (day1[i] == 'C' && day2[i] == 'C')
        {
            occupied += 1;
        }
    }

    printf("%d", occupied);
}