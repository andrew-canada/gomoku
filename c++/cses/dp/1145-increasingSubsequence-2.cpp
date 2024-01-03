#include <bits/stdc++.h>

using namespace std;

const int mxN = 1e5 * 2;

int main()
{
    int n;
    cin >> n;
    vector<int> seq;
    int x;
    for (int i = 0; i < n; i++)
    {
        cin >> x;
        int idx = lower_bound(seq.begin(), seq.end(), x) - seq.begin();
        if (idx < seq.size())
        {
            seq[idx] = x;
        }
        else
        {
            seq.push_back(x);
        }
    }
    cout << seq.size();
}

/*
8
7 3 5 3 6 2 9 8

8
7 3 5 3 6 1 2 8

5
4 5 1 2 3
*/