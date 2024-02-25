/*
rolling hash (sliding window) to find exact pattern string match
similar to math: finding all 4-digit numbers in 40 consecutive digits
1. initialize hash values and base values
2. initialize hash of first n characters
3. hash with sliding window
    a) assign an integer value to all characters
    b) add new character and subtract old character
    c) characters have a base value: abc = 1*100 + 2*10 + 3
*/

#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

const int mxN = 100, numChar = 4, M = 1e9 + 7;

vector<int> rabinKarp(string s, string t)
{
    vector<int> ans;
    int sl = s.size(), tl = t.size();
    int mxPos = 1;
    for (int i = 0; i < tl - 1; i++)
    {
        mxPos = mxPos * numChar % M;
    }
    int sh = 0, th = 0;
    for (int i = 0; i < tl; i++)
    {
        sh = (sh * numChar + (s[i] - 'a' + 1)) % M;
        th = (th * numChar + (t[i] - 'a' + 1)) % M;
    }
    for (int i = 0; i <= sl - tl; i++)
    {
        if (sh == th)
        {
            bool valid = true;
            for (int j = 0; j < tl; j++)
            {
                if (s[i + j] != t[j])
                {
                    valid = false;
                    break;
                }
            }
            if (valid)
            {
                ans.pb(i);
            }
        }
        if (i < sl - tl)
        {
            sh = ((sh - (s[i] - 'a' + 1) * mxPos) * numChar + (s[i + tl] - 'a' + 1)) % M;
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
    string s = "abcdab", t = "ab";
    vector<int> v = rabinKarp(s, t);
    for (int i : v)
    {
        cout << i << " ";
    }
}