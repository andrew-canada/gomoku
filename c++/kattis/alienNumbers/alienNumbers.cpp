#include <stdio.h>
#include <string>

using namespace std;

char in[95];
int cases;
int srcBase, tarBase;
int rem;

int main()
{
    scanf("%d", &cases);
    for (int i = 1; i <= cases; i++)
    {
        scanf("%s", &in);
        string num(in);
        scanf("%s", &in);
        string src(in);
        scanf("%s", &in);
        string tar(in);

        string ans = "";
        int decVal = 0;
        srcBase = src.length();
        for (char d : num)
        {
            decVal = decVal * srcBase + src.find(d);
        }

        tarBase = tar.length();
        while (decVal > 0)
        {
            rem = decVal % tarBase;
            ans = tar[rem] + ans;
            decVal /= tarBase;
        }

        printf("Case #%d: %s\n", i, ans.c_str());
    }
}