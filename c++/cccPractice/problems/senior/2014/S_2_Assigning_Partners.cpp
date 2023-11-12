#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

int n;
string names[35];
string name;
unordered_map<string, string> nm;

int main()
{
    scanf("%d", &n);
    REP(i, 0, n)
    {
        cin >> names[i];
    }
    REP(i, 0, n)
    {
        cin >> name;
        nm[names[i]] = name;
        if (names[i] == name)
        {
            cout << "bad";
            return 0;
        }
    }
    REP(i, 0, n)
    {
        if (nm[nm[names[i]]] != names[i])
        {
            cout << "bad";
            return 0;
        }
    }
    cout << "good";
}