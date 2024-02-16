#include <bits/stdc++.h>

using namespace std;

#define pb push_back

map<string, char> mp;

int main()
{
    int k;
    cin >> k;
    char c;
    string num;
    vector<string> v;
    for (int i = 0; i < k; i++)
    {
        cin >> c >> num;
        mp[num] = c;
        v.pb(num);
    }
    string s;
    cin >> s;
    while (s.size())
    {
        for (string st : v)
        {
            if (s.find(st) == 0)
            {
                s = s.substr(st.size());
                cout << mp[st];
            }
        }
    }
}

/*
5
A 00
B 01
C 10
D 110
E 111
00000101111
*/