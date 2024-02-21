#include <bits/stdc++.h>
using namespace std;

void make_move(int start, int helper, int end, int count)
{
    if (count == 1)
    {
        cout << start << " " << end << endl;
        return;
    }
    make_move(start, end, helper, count - 1);
    cout << start << " " << end << endl;
    make_move(helper, start, end, count - 1);
}

int main()
{
    int n;
    cin >> n;

    cout << (1 << n) - 1 << endl;
    make_move(1, 2, 3, n);
}