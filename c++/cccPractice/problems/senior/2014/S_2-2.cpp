#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int mxN = 30;

map<string, string> mp;
string arr[mxN + 1];

int main()
{
    int n;
    cin >> n;
    string s;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> s;
        mp[arr[i]] = s;
    }
    for (int i = 0; i < n; i++)
    {
        if (arr[i] != mp[mp[arr[i]]] || arr[i] == mp[arr[i]])
        {
            cout << "bad";
            return 0;
        }
    }
    cout << "good";
}