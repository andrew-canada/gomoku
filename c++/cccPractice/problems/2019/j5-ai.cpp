#include <iostream>
#include <cstring>
#include <map>
#include <vector>

using namespace std;

const int MAXN = 60;
int s, len1, len2;
string a[3], b[3], I, F, tmp;
map<string, int> ma;
vector<pair<int, pair<int, string>>> vec;

bool dfs(int step, string now)
{
    if (step == s)
    {
        if (now == F)
            return true;
        else
            return false;
    }
    for (int i = 0; i < 3; i++)
    {
        int pos = now.find(a[i], 0);
        while (pos != string::npos)
        {
            tmp = now;
            now.replace(pos, b[i].size(), b[i]);
            vec.push_back(make_pair(i + 1, make_pair(pos + 1, now)));
            if (dfs(step + 1, now))
                return true;
            vec.pop_back();
            now = tmp;
            pos = now.find(b[i], pos + len2);
        }
    }
    return false;
}

int main()
{
    for (int i = 0; i < 3; i++)
    {
        cin >> a[i] >> b[i];
        ma[a[i]] = i + 1;
    }
    cin >> s >> I >> F;
    len1 = I.size();
    len2 = b[0].size();
    if (dfs(0, I))
    {
        for (int i = 0; i < vec.size(); i++)
            cout << vec[i].first << " " << vec[i].second.first << " " << vec[i].second.second << endl;
    }
    return 0;
}
