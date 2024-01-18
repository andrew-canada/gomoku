#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 2e5;

int n, k;
int arr[mxN + 1];
array<int, 2> med = {-1};
set<array<int, 2>> low, high;

void fix()
{
    int nt = low.size() + high.size() + 1;
    if (low.size() > (nt - 1) / 2)
    {
        high.insert(med);
        med = *--low.end();
        low.erase(med);
    }
    if (low.size() < (nt - 1) / 2)
    {
        low.insert(med);
        med = *high.begin();
        high.erase(med);
    }
}

void add(array<int, 2> cur)
{
    if (med[0] == -1)
    {
        med = cur;
        return;
    }
    if (cur >= med)
    {
        high.insert(cur);
    }
    else
    {
        low.insert(cur);
    }
    fix();
}

void rem(array<int, 2> cur)
{
    if (cur == med)
    {
        // med = *--low.end();
        // low.erase(med);
        med = *high.begin();
        high.erase(med);
    }
    else if (cur > med)
    {
        high.erase(cur);
    }
    else
    {
        low.erase(cur);
    }
    fix();
}

int main()
{
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (k == 1)
    {
        for (int i = 0; i < n; i++)
        {
            cout << arr[i] << " ";
        }
        return 0;
    }
    for (int i = 0; i < k - 1; i++)
    {
        add({arr[i], i});
    }
    for (int i = k - 1; i < n; i++)
    {
        add({arr[i], i});
        cout << med[0] << " ";
        rem({arr[i - k + 1], i - k + 1});
    }
}