#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

// #define gc getchar()
// template <typename T>
// void scan(T &x)
// {
//     char ch;
//     while ((ch = gc) != ' ')
//     {
//         scan(ch);
//     }
// }

int main()
{
    char names[6];
    int character, counter = 0;
    do
    {
        character = getchar();
        if (character == ' ')
        {
            break;
        }
        names[counter] = character;
        counter += 1;
    } while (counter <= 5);

    for (int i = 0; i < sizeof(names) / sizeof(names[0]); i++)
    {
        printf("%c", names[i]);
    }

    // char a[3], b[3];
    // scan(a);
    // scan(b);
    // printf("%s %s\n", a, b);
}
