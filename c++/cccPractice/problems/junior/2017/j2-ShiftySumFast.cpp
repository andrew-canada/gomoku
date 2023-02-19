#include <stdio.h>

int main()
{
    int number, numberOfShifts;
    scanf("%d%d", &number, &numberOfShifts);

    int ans = number;

    for (int i = 0; i < numberOfShifts; i++)
    {
        number *= 10;
        ans += number;
    }

    printf("%d", ans);
}