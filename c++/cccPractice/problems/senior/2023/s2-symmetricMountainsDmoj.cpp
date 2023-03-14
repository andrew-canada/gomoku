#include <iostream>
#include <vector>

using namespace std;

const int INF = 0x3f3f3f3f;

int main()
{
    cin.sync_with_stdio(0);
    cin.tie(0);
    int n;
    cin >> n;
    vector<int> h(n);
    for (int &i : h)
    {
        cin >> i;
    }
    vector<int> ans(n + 1, INF);
    for (int i = 0; i < n; i++)
    {
        // odd
        for (int l = 0, v = 0; i - l >= 0 && i + l < n; l++)
        {
            v += abs(h[i - l] - h[i + l]);
            ans[1 + l * 2] = min(v, ans[1 + l * 2]);
        }
        // even
        for (int l = 0, v = 0; i - l >= 0 && i + l + 1 < n; l++)
        {
            v += abs(h[i - l] - h[i + l + 1]);
            ans[(l + 1) * 2] = min(v, ans[(l + 1) * 2]);
        }
    }
    for (int i = 1; i <= n; i++)
    {
        cout << ans[i] << (i == n ? '\n' : ' ');
    }
}