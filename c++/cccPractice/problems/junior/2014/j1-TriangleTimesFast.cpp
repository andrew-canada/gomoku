#include <stdio.h>

int main()
{
    int angle1 = 0, angle2 = 0, angle3 = 0;
    scanf("%d%d%d", &angle1, &angle2, &angle3);

    if (angle1 + angle2 + angle3 == 180)
    {
        if (angle1 == angle2 && angle1 == 60)
        {
            puts("Equilateral");
        }
        else if (angle1 != angle2 && angle1 != angle3 && angle2 != angle3)
        {
            puts("Scalene");
        }
        else
        {
            puts("Isosceles");
        }
    }
    else
    {
        puts("Error");
    }
}