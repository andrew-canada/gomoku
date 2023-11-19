#include <bits/stdc++.h>
using namespace std;

unordered_map<int, int> freq;

int main()
{
    int t, n;
    int op;
    int val;
    int curV, curF;
    scanf("%d", &t);
    while (t--)
    {
        op = 0;
        scanf("%d", &n);
        for (int i = 0; i < n; i++)
        {
            scanf("%d", &val);
            freq[val]++;
        }
        for (const auto &e : freq)
        {
            curV = e.first, curF = e.second;
            if (curF > curV)
            {
                op += curF - curV;
            }
            else if (curF < curV)
            {
                op += min(curF, curV - curF);
            }
        }
        printf("%d\n", op);
        freq.clear();
    }
    return 0;
}

/*
1
5
3 2 3 1 2
*/