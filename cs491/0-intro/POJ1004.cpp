#include <stdio.h>

int main()
{
    float sum = 0;
    float val;
    for (int i = 0; i < 12; i++)
    {
        scanf("%f", &val);
        sum += val;
    }
    printf("$%.2f\n", sum / 12);
    return 0;
}