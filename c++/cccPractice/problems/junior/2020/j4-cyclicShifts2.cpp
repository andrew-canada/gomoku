#include <stdio.h>
#include <string>

using namespace std;

char tin[1001], strin[1001];
int slen;

int main()
{
    scanf("%s%s", &tin, &strin);
    string t(tin);
    string s(strin);
    slen = s.length();

    for (int i = 0; i < slen; i++)
    {
        if (t.find(s) != string::npos)
        {
            printf("yes");
            return 0;
        }
        s = s.substr(1) + s[0];
    }
    printf("no");
}