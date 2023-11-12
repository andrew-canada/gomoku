#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

int n;
char arr[100005];
int h = 100005;
int dist;
unordered_map<char, int> m;

int main()
{
    scanf("%d", &n);
    scanf("%s", &arr);
    unordered_set<char> s(arr, arr + n);
    dist = s.size();
    int l = 0, r = -1;
    while (r < n)
    {
        if (m.size() == dist)
        {
            h = min(h, r - l + 1);
            m[arr[l]]--;
            if (m[arr[l]] == 0)
            {
                m.erase(arr[l]);
            }
            l++;
            continue;
        }
        r++;
        m[arr[r]]++;
    }

    printf("%d", h);
}