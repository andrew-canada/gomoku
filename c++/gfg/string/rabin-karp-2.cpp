#include <bits/stdc++.h>

using namespace std;

const int numCh = 4, M = 1e9 + 7;

vector<int> rk(string s, string t)
{
    vector<int> ans;
    int sl = s.size(), tl = t.size();
    int mxH = 1;
    for (int i = 0; i < tl - 1; i++)
    {
        mxH = (mxH * numCh) % M;
    }
    int th = 0;
    int sh = 0;
    for (int i = 0; i < tl; i++)
    {
        th = (th * numCh + (t[i] - 'a' + 1)) % M;
        sh = (sh * numCh + (s[i] - 'a' + 1)) % M;
    }
    for (int i = 0; i <= sl - tl; i++)
    {
        if (th == sh)
        {
            bool found = true;
            for (int j = 0; j < tl; j++)
            {
                if (t[j] != s[i + j])
                {
                    found = false;
                    break;
                }
            }
            if (found)
            {
                ans.push_back(i);
            }
        }
        if (i < sl - tl)
        {
            sh = ((sh - (s[i] - 'a' + 1) * mxH) * mxH + (s[i + tl] - 'a' + 1)) % M;
            if (sh < 0)
            {
                sh += M;
            }
        }
    }
    return ans;
}

int main()
{
    string s = "ababcd", t = "ab";
    vector<int> ans = rk(s, t);
    for (int i : ans)
    {
        cout << i << " ";
    }
}