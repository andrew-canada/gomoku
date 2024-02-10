#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

map<char, int> rta = {{'I', 1}, {'V', 5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}};

int main()
{
    string s;
    cin >> s;
    int n = s.size();
    int ans = (s[n - 2] - '0') * rta[s[n - 1]];
    for (int i = 0; i < s.size() - 2; i += 2)
    {
        if (rta[s[i + 1]] < rta[s[i + 3]])
        {
            ans -= (s[i] - '0') * rta[s[i + 1]];
        }
        else
        {
            ans += (s[i] - '0') * rta[s[i + 1]];
        }
    }
    cout << ans;
}