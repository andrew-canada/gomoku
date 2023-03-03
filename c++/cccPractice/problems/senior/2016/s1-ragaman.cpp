#include <stdio.h>
#include <string>

int s1chars[123];
int s2chars[123];
char line[101];

int main()
{
    s1chars['*'] = 123;

    scanf("%s", &line);
    std::string s1(line);
    for (char c : s1)
    {
        s1chars[c]++;
    }

    scanf("%s", &line);
    std::string s2(line);
    for (char c : s2)
    {
        s2chars[c]++;
        if (s2chars[c] > s1chars[c])
        {
            printf("N");
            return 0;
        }
    }
    printf("A");
}