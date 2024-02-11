#include <bits/stdc++.h>

using namespace std;

int main()
{
    int n;
    cin >> n;
    string s;
    int nt = 0, ns = 0;
    getline(cin, s);
    for (int i = 0; i < n; i++)
    {
        getline(cin, s);
        for (char c : s)
        {
            if (c == 't' || c == 'T')
            {
                nt++;
            }
            else if (c == 's' || c == 'S')
            {
                ns++;
            }
        }
    }
    if (ns >= nt)
    {
        cout << "French";
    }
    else
    {
        cout << "English";
    }
}