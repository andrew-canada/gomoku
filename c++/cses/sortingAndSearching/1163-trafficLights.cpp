#include <bits/stdc++.h>

using namespace std;

const int mxN = 2e5;

set<int> tl;
map<int, int> st;

int main()
{
    int x, n;
    cin >> x >> n;
    tl.insert(0), tl.insert(x);
    st[x] = 1;
    for (int i = 0; i < n; i++)
    {
        int p;
        cin >> p;
        auto it = tl.lower_bound(p);
        int r = *it, l = *(--it);
        st[r - l]--;
        if (!st[r - l])
        {
            st.erase(r - l);
        }
        tl.insert(p);
        ++st[r - p], ++st[p - l];
        cout << (--st.end())->first << " ";
    }
}