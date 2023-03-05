#include <stdio.h>
#include <vector>

typedef std::vector<int> vi;

vi newInv;
int n;
int l;
int f;

int main()
{
    scanf("%d%d", &n, &l);
    vi inv(n);
    for (int i = 1; i <= n; i++)
    {
        inv[i - 1] = i;
    }
    while (l--)
    {
        scanf("%d", &f);
        for (int i = 0; i < inv.size(); i++)
        {
            if ((i + 1) % f != 0)
            {
                newInv.push_back(inv[i]);
            }
        }
        inv = newInv;
        newInv.clear();
    }
    for (int i : inv)
    {
        printf("%d\n", i);
    }
}