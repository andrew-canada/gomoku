#include <stdio.h>

using namespace std;

int main()
{
    int n;
    scanf("%d", &n);
    int *data = new int[n * n];

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            scanf("%d", (data + i * n + j));
        }
    }
    int tl = data[0];
    int tr = *(data + n - 1);
    int bl = *(data + n * (n - 1));
    int br = *(data + n * n - 1);

    // min in top left
    if ((tl < tr) && (tl < bl) && (tl < br))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%d ", *(data + i * n + j));
            }
            printf("\n");
        }
    }

    // min in top right
    if ((tr < tl) && (tr < bl) && (tr < br))
    {
        for (int i = 1; i <= n; i++)
        {
            for (int j = 1; j <= n; j++)
            {
                printf("%d ", *(data + n * j - i));
            }
            printf("\n");
        }
    }

    // min in bottom right
    if ((br < tl) && (br < bl) && (br < tr))
    {
        for (int i = n; i > 0; i--)
        {
            for (int j = 1; j <= n; j++)
            {
                printf("%d ", *(data + n * i - j));
            }
            printf("\n");
        }
    }

    // min in bottom left
    if ((bl < tl) && (bl < br) && (bl < tr))
    {
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%d ", *(data + n * (n - 1) + i - n * j));
            }
            printf("\n");
        }
    }
}