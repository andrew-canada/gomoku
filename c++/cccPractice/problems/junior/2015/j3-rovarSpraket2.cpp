#include <stdio.h>
#include <string>

char in[31];

int main()
{
    scanf("%s", &in);
    std::string msg(in);
    for (char c : msg)
    {
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
        {
            printf("%c", c);
        }
        else
        {
            printf("%c", c);
            if (c > 'a' && c < 'e')
            {
                if (c > ('a' + 'e') / 2)
                {
                    printf("e");
                    if (c + 1 == 'e')
                    {
                        printf("%c", c + 2);
                    }
                    else
                    {
                        printf("%c", c + 1);
                    }
                }
                else
                {
                    printf("a");
                    printf("%c", c + 1);
                }
            }
            else if (c > 'e' && c < 'i')
            {
                if (c > ('e' + 'i') / 2)
                {
                    printf("i");
                    if (c + 1 == 'i')
                    {
                        printf("%c", c + 2);
                    }
                    else
                    {
                        printf("%c", c + 1);
                    }
                }
                else
                {
                    printf("e");
                    printf("%c", c + 1);
                }
            }
            else if (c > 'i' && c < 'o')
            {
                if (c > ('i' + 'o') / 2)
                {
                    printf("o");
                    if (c + 1 == 'o')
                    {
                        printf("%c", c + 2);
                    }
                    else
                    {
                        printf("%c", c + 1);
                    }
                }
                else
                {
                    printf("i");
                    printf("%c", c + 1);
                }
            }
            else if (c > 'o' && c < 'u')
            {
                if (c > ('o' + 'u') / 2)
                {
                    printf("u");
                    if (c + 1 == 'u')
                    {
                        printf("%c", c + 2);
                    }
                    else
                    {
                        printf("%c", c + 1);
                    }
                }
                else
                {
                    printf("o");
                    printf("%c", c + 1);
                }
            }
            else
            {
                printf("u");
                if (c == 'z')
                {
                    printf("z");
                }
                else
                {
                    printf("%c", c + 1);
                }
            }
        }
    }
}