#include <stdio.h>
#include <string>

int n;
char ln[81];
int r = 1;

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%s", &ln);
        std::string msg(ln);
        for (int i = 0; i < msg.size(); i++)
        {
            if (msg[i] == msg[i + 1])
            {
                r += 1;
            }
            else
            {
                printf("%d %c ", r, msg[i]);
                r = 1;
            }
        }
        printf("\n");
    }
}