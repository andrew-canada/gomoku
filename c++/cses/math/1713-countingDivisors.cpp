#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef long long ll;

const int M = 1e9 + 7;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        int x;
        cin >> x;
        int ans = 0;
        for (int i = 1; i * i <= x; i++)
        {
            if (x % i == 0)
            {
                if (i * i == x)
                {
                    ans++;
                }
                else
                {
                    ans += 2;
                }
            }
        }
        cout << ans << '\n';
    }
}