#include <stdio.h>

int main()
{
    int nF, nB, bF, bB, stepLim;
    int numSteps = 0, nikkyDist = 0, byronDist = 0;
    scanf("%d%d%d%d%d", &nF, &nB, &bF, &bB, &stepLim);

    while (numSteps < stepLim)
    {

        for (int i = 0; i < nF; i++)
        {
            if (numSteps == stepLim)
            {
                break;
            }
            nikkyDist += 1;
            numSteps += 1;
        }

        for (int i = 0; i < nB; i++)
        {
            if (numSteps == stepLim)
            {
                break;
            }
            nikkyDist -= 1;
            numSteps += 1;
        }
    }

    numSteps = 0;
    while (numSteps < stepLim)
    {

        for (int i = 0; i < bF; i++)
        {
            if (numSteps == stepLim)
            {
                break;
            }
            byronDist += 1;
            numSteps += 1;
        }

        for (int i = 0; i < bB; i++)
        {
            if (numSteps == stepLim)
            {
                break;
            }
            byronDist -= 1;
            numSteps += 1;
        }
    }

    if (nikkyDist > byronDist)
    {
        puts("Nikky");
    }
    else if (nikkyDist < byronDist)
    {
        puts("Byron");
    }
    else
    {
        puts("Tied");
    }
}