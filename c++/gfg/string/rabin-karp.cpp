#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int M = 1e9 + 7, nc = 256;

vector<int> search(string t, string s1)
{
    vector<int> ans;
    int h = 1;
    for (int i = 1; i < s1.size(); i++)
    {
        h = (h * nc) % M;
    }
    int s1H = 0, tH = 0;
    for (int i = 0; i < s1.size(); i++)
    {
        s1H = (s1H * nc + (s1[i] - 'a' + 1)) % M;
        tH = (tH * nc + (t[i] - 'a' + 1)) % M;
    }
    for (int i = 0; i <= t.size() - s1.size(); i++)
    {
        if (s1H == tH)
        {
            bool found = true;
            for (int j = 0; j < s1.size(); j++)
            {
                if (s1[j] != t[j + i])
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
        if (i < t.size() - s1.size())
        {
            tH = (nc * (tH - (t[i] - 'a' + 1) * h) + (t[i + s1.size()] - 'a' + 1)) % M;
            if (tH < 0)
            {
                tH += M;
            }
        }
    }
    return ans;
}

int main()
{
    string t = "abcbadefabc";
    string s1 = "abc";
    vector<int> ans = search(t, s1);
    for (int i : ans)
    {
        cout << i << " ";
    }
}