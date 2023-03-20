#include <stdio.h>
#include <math.h>

int n;
int val;
int sum;

bool isPrime(const int &n)
{
    for (int i = 2; i <= sqrt(n); i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

int main()
{
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &val);
        sum = val * 2;
        for (int i = 3; i <= sum / 2; i += 2)
        {
            if (isPrime(i) && isPrime(sum - i))
            {
                printf("%d %d\n", i, sum - i);
                break;
            }
        }
    }
}