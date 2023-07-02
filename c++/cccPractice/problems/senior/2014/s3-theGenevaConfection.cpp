#include <stdio.h>

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

int t, n, curCar;
int unordCar, prevUnordCar;
int cars[100005];

int main()
{
    scanf("%d", &t);
    REP(i, 0, t)
    {
        scanf("%d", &n);
        curCar = 1;
        unordCar = n + 1;
        bool possible = true;
        for (int i = n - 1; i >= 0; i--)
        {
            scanf("%d", &cars[i]);
        }
        REP(i, 0, n)
        {
            if (cars[i] == curCar)
            {
                curCar++;
            }
            else
            {
                if (unordCar == curCar)
                {
                    unordCar = prevUnordCar;
                }
                else if (cars[i] < unordCar)
                {
                    unordCar = cars[i];
                    prevUnordCar = unordCar;
                }
                else
                {
                    printf("N\n");
                    possible = false;
                    break;
                }
            }
        }
        if (possible)
        {
            printf("Y\n");
        }
    }
}