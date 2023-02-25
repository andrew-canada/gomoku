#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
#include <vector>
#include <algorithm>
#include <utility>

using namespace std;

#define LOCAL
typedef map<string, int> msi;
typedef map<string, vector<string>> msvs;
typedef vector<pair<string, int>> vpsi;

msi p;
msvs smp;
string s;
string cur;

int main()
{
#ifdef LOCAL
    freopen("11239-2.in", "r", stdin);
    freopen("11239.out", "w", stdout);
#endif

    while (getline(cin, s), s != "0")
    {
        p[s] = 0;
        cur = s;
        while (getline(cin, s), s != "1")
        {
            if (s[0] >= 97)
            {
                if (count(smp[s].begin(), smp[s].end(), cur) == 0)
                {
                    smp[s].push_back(cur);
                    p[cur]++;
                }
            }
            else
            {
                p[s] = 0;
                cur = s;
            }
        }

        for (const auto &student : smp)
        {
            if (student.second.size() > 1)
            {
                for (const string &project : student.second)
                {
                    p[project]--;
                }
            }
        }

        vpsi ans(p.begin(), p.end());
        std::sort(ans.begin(), ans.end(), [](const auto &p1, const auto &p2)
                  { return p2.second < p1.second; });
        for (auto &[k, v] : ans)
        {
            printf("%s %d\n", k.c_str(), v);
        }
        p.clear();
        smp.clear();
    }
}