#include <stdio.h>
#include <string>

char in[256];
int h, sad;

int main()
{
    // scanf("%s", &in);
    fgets(in, 256, stdin);
    std::string s(in);
    int msgSize = s.size();
    for (int i = 0; i < msgSize; i++)
    {
        if (s[i] == ':')
        {
            if (i + 1 < msgSize && s[i + 1] == '-')
            {
                if (i + 2 < msgSize && s[i + 2] == ')')
                {
                    h += 1;
                }
                else if (i + 2 < msgSize && s[i + 2] == '(')
                {
                    sad += 1;
                }
                i += 2;
            }
            else
            {
                i += 1;
            }
        }
    }

    if (h > sad)
    {
        printf("happy");
    }
    else if (sad > h)
    {
        printf("sad");
    }
    else if (h != 0 && (h == sad))
    {
        printf("unsure");
    }
    else
    {
        printf("none");
    }
}