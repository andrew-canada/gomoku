#include <bits/stdc++.h>

using namespace std;

#define pb push_back

const int mxN = 1e5;

int arr[mxN + 1];

int main()
{
    int t, n;
    vector<int> v;
    cin >> t;
    while (t--)
    {
        cin >> n;
        int need = 1, x;
        for (int i = 0; i < n; i++)
        {
            cin >> arr[i];
        }
        for (int i = n - 1; i >= 0; i--)
        {
            x = arr[i];
            if (x == need)
            {
                need++;
            }
            else
            {
                while (v.size() && v.back() == need)
                {
                    need++;
                    v.pop_back();
                }
                if (x == need)
                {
                    need++;
                    while (v.size() && v.back() == need)
                    {
                        need++;
                        v.pop_back();
                    }
                }
                else
                {
                    v.pb(x);
                }
            }
        }
        while (v.size() && v.back() == need)
        {
            need++;
            v.pop_back();
        }
        if (v.size())
        {
            cout << "N\n";
        }
        else
        {
            cout << "Y\n";
        }
        v.clear();
    }
}