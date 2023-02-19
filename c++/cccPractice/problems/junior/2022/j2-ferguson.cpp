#include <stdio.h>

int main()
{
    int players;
    scanf("%d", &players);
    int gCount = 0, plus, minus;
    for (int i = 0; i < players; i++)
    {
        scanf("%d%d", &plus, &minus);
        if (plus * 5 - minus * 3 > 40)
        {
            gCount += 1;
        }
    }
    printf("%d", gCount);
    if (players == gCount)
    {
        puts("+");
    }
}