#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

int t;
int n;
stack<int> s;
int curNeed;
int cars[100005];

int main()
{
    scanf("%d", &t);
    REP(i, 0, t)
    {
        scanf("%d", &n);
        curNeed = 1;
        s.push(-1);
        REP(j, 0, n)
        {
            scanf("%d", &cars[j]);
        }
        for (int j = n - 1; j >= 0; j--)
        {
            if (cars[j] == curNeed)
            {
                curNeed++;
            }
            else
            {
                while (!s.empty())
                {
                    if (s.top() == curNeed)
                    {
                        s.pop();
                        curNeed++;
                    }
                    else
                    {
                        s.push(cars[j]);
                        break;
                    }
                }
            }
        }
        while (!s.empty())
        {
            if (s.top() == curNeed)
            {
                s.pop();
                curNeed++;
            }
            else
            {
                break;
            }
        }
        // printf("%d\n", curNeed);
        if (curNeed == n + 1)
        {
            printf("Y\n");
        }
        else
        {
            printf("N\n");
        }
    }
}