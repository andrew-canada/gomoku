#include <stdio.h>
#include <math.h>

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

int n, avg;

bool isPrime(int n);

int main()
{
    scanf("%d", &n);
    int sum;
    int n2;
    REP(i, 0, n)
    {
        scanf("%d", &avg);
        sum = avg * 2;
        REP(i, 3, avg + 1)
        {
            if (isPrime(i))
            {
                n2 = sum - i;
                if (isPrime(n2))
                {
                    printf("%d %d\n", i, n2);
                    break;
                }
            }
        }
    }
}

bool isPrime(int n)
{
    REP(i, 2, sqrt(n) + 1)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}