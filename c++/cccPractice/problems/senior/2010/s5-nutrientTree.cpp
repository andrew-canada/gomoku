#include <stdio.h>
#include <iostream>
#include <string>
#include <stack>

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

using namespace std;

int x;
string ts;
stack<char> s;
int tree[10000];

int main()
{
    getline(cin, ts);
    if (ts[0] != '(')
    {
        printf("%d", stoi(ts) + x);
        return 0;
    }
    char c;
    int i = 1;
    int l, r;
    s.push('(');
    while (!s.empty())
    {
        string num = "";
        while (tree[i] != ' ')
        {
            if (tree[i] == '(' || tree[i] == ')')
            {
                if (num == "")
                {
                    num = ts[i++];
                    break;
                }
            }
            else
            {
                num += ts[i++];
            }
        }
        if (num == "")
        {
            i += 1;
            continue;
        }
        else
        {
        }
    }
    scanf("%d", &x);
}