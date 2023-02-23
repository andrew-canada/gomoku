#include <stdio.h>

bool check(int time)
{
    int hour = time / 60;
    int min = time % 60;
    if (hour == 0)
    {
        hour = 12;
    }
    if (hour > 9)
    {
        int t1 = hour / 10 - hour % 10;
        int t2 = hour % 10 - min / 10;
        int t3 = min / 10 - min % 10;
        return t1 == t2 && t2 == t3;
    }
    int t1 = hour - min / 10;
    int t2 = min / 10 - min % 10;
    return t1 == t2;
}

bool ok[720];
int sum;

int duration, ans;

int main()
{
    for (int i = 0; i < 720; i++)
    {
        ok[i] = check(i);
        if (ok[i])
            sum++;
    }
    scanf("%d", &duration);
    duration++;
    ans += sum * (duration / 720);
    for (int i = 0; i < duration % 720; i++)
    {
        if (ok[i])
            ans++;
    }
    printf("%d", ans);
}