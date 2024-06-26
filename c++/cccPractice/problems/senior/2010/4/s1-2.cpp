// 22min due to failed first attempt

#include <bits/stdc++.h>

using namespace std;

struct cpt
{
    int v;
    string s;
};

bool srt(const cpt &cpt1, const cpt &cpt2)
{
    return cpt1.v == cpt2.v ? cpt1.s < cpt2.s : cpt1.v > cpt2.v;
}

int main()
{
    int n;
    cin >> n;
    int v, r, c, d;
    string s;
    vector<cpt> ans;
    for (int i = 0; i < n; i++)
    {
        cin >> s >> r >> c >> d;
        v = 2 * r + 3 * c + d;
        ans.push_back({v, s});
    }
    sort(ans.begin(), ans.end(), srt);
    if (ans.size() == 0)
    {
        return 0;
    }
    else if (ans.size() == 1)
    {
        cout << ans[0].s;
    }
    else
    {
        cout << ans[0].s << '\n'
             << ans[1].s;
    }
}