#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 2e5;

int main()
{
    set<array<int, 2>> s;
    // end and begin are the same if set is empty
    // when set isn't empty, end is the imaginary term after the last term
    cout << (*s.begin())[0] << (*s.begin())[1] << '\n';
    // cout << (*--s.end())[0] << (*--s.end())[1] << '\n';
}