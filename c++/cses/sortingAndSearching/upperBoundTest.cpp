#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f

set<array<int, 2>> s;

int main()
{
    s.insert({1, 2});
    auto it = s.upper_bound({5});
    s.insert({5, 0});
    it = s.upper_bound({5});
    cout << (*it)[0] << " " << (*it)[1] << '\n';
    s.insert({5, 1});
    it = s.upper_bound({5});
    cout << (*it)[0] << " " << (*it)[1] << '\n';
    it = s.upper_bound({5, 1});
    cout << (*it)[0] << " " << (*it)[1] << '\n';
    it = s.upper_bound({5, 0});
    cout << (*it)[0] << " " << (*it)[1] << '\n';
}