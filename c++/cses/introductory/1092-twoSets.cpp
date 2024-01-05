#include <bits/stdc++.h>

using namespace std;

#define pb push_back

typedef long long ll;

int main()
{
    ll n;
    cin >> n;
    if ((n * (n + 1) / 2) & 1)
    {
        cout << "NO\n";
        return 0;
    }
    vector<int> set1, set2;
    int offSet;
    if (n & 1)
    {
        offSet = 3;
    }
    else
    {
        offSet = 4;
    }
    for (int i = 0; i < (n - 1) / 4; i++)
    {
        set1.pb(i * 4 + 1 + offSet), set1.pb(i * 4 + 4 + offSet);
        set2.pb(i * 4 + 2 + offSet), set2.pb(i * 4 + 3 + offSet);
    }
    if (n & 1)
    {
        set1.pb(1), set1.pb(2);
        set2.pb(3);
    }
    else
    {
        set1.pb(1), set1.pb(4);
        set2.pb(2), set2.pb(3);
    }

    cout << "YES\n";
    cout << set1.size() << "\n";
    for (int i : set1)
    {
        cout << i << " ";
    }
    cout << "\n";
    cout << set2.size() << "\n";
    for (int i : set2)
    {
        cout << i << " ";
    }
    cout << "\n";
}