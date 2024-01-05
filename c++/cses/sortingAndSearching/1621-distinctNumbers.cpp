#include <bits/stdc++.h>

using namespace std;

set<int> s;

int main()
{
    int n;
    cin >> n;
    int v;
    for (int i = 0; i < n; i++)
    {
        cin >> v;
        s.insert(v);
    }
    cout << s.size();
}