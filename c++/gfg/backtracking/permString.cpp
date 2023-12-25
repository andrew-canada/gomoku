#include <bits/stdc++.h>

using namespace std;

bool isSafe(string str, int l, int r, int i);
void perm(string str, int l, int r);

int main()
{
    string str = "ABC";
    perm(str, 0, str.length() - 1);
}

bool isSafe(string str, int l, int r, int i)
{
    if (l > 0 && str[l - 1] == 'A' && str[i] == 'B')
    {
        return false;
    }
    if (l + 1 == r && str[l] == 'B' && str[i] == 'A')
    {
        return false;
    }
    return true;
}

void perm(string str, int l, int r)
{
    if (l == r)
    {
        printf("%s\n", str.c_str());
        return;
    }
    for (int i = l; i <= r; i++)
    {
        if (isSafe(str, l, r, i))
        {
            swap(str[l], str[i]);
            perm(str, l + 1, r);
            swap(str[l], str[i]);
        }
    }
}