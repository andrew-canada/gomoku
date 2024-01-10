#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int r, c;
        cin >> r >> c;
        int msl = max(r, c);
        int ans = (msl - 1) * (msl - 1);
        if (msl & 1)
        {
            if (msl == r)
            {
            }
            else
            {
            }
        }
        else
        {
            if (msl == r)
            {
            }
            else
            {
            }
        }
        cout << ans << '\n';
    }
}