#include <stdio.h>

#define REPi(i, a, b) for (int i = int(a); i < int(b); i++)
#define MIN(x, y) x < y ? x : y

int b[2005];
int longest;
int numF = -1;
int len = -1;
int n;

int main()
{
    scanf("%d", &n);
    REPi(i, 0, n)
    {
        scanf("%d", &len);
        b[len]++;
    }
    for (int h = 2; h <= 4000; h++)
    {
        int curLen = 0;
        for (int b1 = 1; b1 <= h / 2; b1++)
        {
            if (h - b1 <= 2000)
            {
                if (b1 == h - b1)
                {
                    curLen += b[(int)b1] / 2;
                }
                else
                {
                    curLen += MIN(b[b1], b[h - b1]);
                }
            }
        }
        if (curLen > longest)
        {
            longest = curLen;
            numF = 1;
        }
        else if (curLen == longest)
        {
            numF++;
        }
    }
    printf("%d %d", longest, numF);
}
