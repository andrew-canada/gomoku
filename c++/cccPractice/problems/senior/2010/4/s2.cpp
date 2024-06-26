// 6min

#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<string> v;
    map<string, char> mp;
    char c;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> c >> s;
        v.push_back(s);
        mp[s] = c;
    }
    string st;
    cin >> st;
    while (st.size())
    {
        for (string seq : v)
        {
            if (st.find(seq) == 0)
            {
                cout << mp[seq];
                st = st.substr(seq.size());
                break;
            }
        }
    }
}