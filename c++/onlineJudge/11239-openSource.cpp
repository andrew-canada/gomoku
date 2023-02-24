#include <stdio.h>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace std;

// #define LOCAL
typedef map<string, int> msi;
typedef map<string, vector<string>> msvs;

msi p;
msvs smp;
string s;
string cur;

int main()
{
#ifdef LOCAL
    freopen("11239.in", "r", stdin);
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
                p[cur]++;
                smp[s].push_back(cur);
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
        for (auto &[k, v] : p)
        {
            printf("%s %d\n", k.c_str(), v);
        }
        p.clear();
        smp.clear();
    }
}