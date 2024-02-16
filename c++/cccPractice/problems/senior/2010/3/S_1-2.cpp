#include <bits/stdc++.h>

using namespace std;

#define pb push_back

struct computer
{
    int score;
    string name;
};

bool comp(const computer &c1, const computer &c2)
{
    return c1.score == c2.score ? c1.name < c2.name : c1.score > c2.score;
}

int main()
{
    int n;
    cin >> n;
    int r, s, d;
    string nm;
    vector<computer> v;
    while (n--)
    {
        cin >> nm >> r >> s >> d;
        v.pb({2 * r + 3 * s + d, nm});
    }
    sort(v.begin(), v.end(), comp);
    if (v.size() == 1)
    {
        cout << v[0].name;
    }
    else if (v.size() >= 2)
    {
        cout << v[0].name << '\n'
             << v[1].name;
    }
}

/*
4
ABC 13 22 1
DEF 10 20 30
GHI 11 2 2
JKL 20 20 20
*/