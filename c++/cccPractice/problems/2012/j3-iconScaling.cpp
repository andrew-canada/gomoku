#include <stdio.h>

int main()
{
    int scaleFactor;
    scanf("%d", &scaleFactor);

    for (int i = 1; i <= scaleFactor * 3; i++)
    {
        for (int j = 1; j <= scaleFactor * 3; j++)
        {
            if ((((i <= scaleFactor &&
                   ((j <= scaleFactor) ||
                    (j > 2 * scaleFactor))) ||
                  ((i > 2 * scaleFactor) &&
                   ((j <= scaleFactor) ||
                    (j > 2 * scaleFactor))))))
            {
                // no newline
                fputs("*", stdout);
            }
            else if ((i <= scaleFactor &&
                      (j > scaleFactor && j < 3 * scaleFactor)) ||
                     ((i > scaleFactor && i <= 2 * scaleFactor) &&
                      j > scaleFactor))
            {
                fputs("x", stdout);
            }
            else
            {
                fputs(" ", stdout);
            }
        }
        fputs("\n", stdout);
    }
}