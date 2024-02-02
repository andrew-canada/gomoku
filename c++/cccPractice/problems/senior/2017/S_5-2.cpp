#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef long long ll;

const int mxN = 1.5e5, rangeSize = 388;

struct range
{
    int np;
    vector<int> left = vector<int>(mxN + 1, INF), right = vector<int>(mxN + 1, INF);
};

int stnLn[mxN + 1], posInLn[mxN + 1], disp[mxN + 1];
vector<int> line[mxN + 1];
range ranges[rangeSize + 1];

int main()
{
    int n, m, q;
    cin >> n >> m >> q;
    for (int i = 1; i <= n; i++)
    {
        cin >> stnLn[i];
    }
    int p;
    for (int i = 1; i <= n; i++)
    {
        cin >> p;
        line[stnLn[i]].pb(p);
        ranges[i / rangeSize].np += p;
        // find leftmost stn number of a line
        ranges[i / rangeSize].left[stnLn[i]] = min((int)line[stnLn[i]].size() - 1,
                                                   ranges[i / rangeSize].left[stnLn[i]]);
        ranges[i / rangeSize].right[stnLn[i]] = line[stnLn[i]].size() - 1;
        // relative position in a line
        posInLn[i] = line[stnLn[i]].size() - 1;
    }
    int type, l, r, x;
    for (int i = 0; i < q; i++)
    {
        cin >> type;
        // query
        if (type == 1)
        {
            cin >> l >> r;
            int ans = 0;
            while (l <= r)
            {
                // entirely in a range
                if (l % rangeSize == 0 && l + rangeSize <= r)
                {
                    ans += ranges[l / rangeSize].np;
                    l += rangeSize;
                }
                // partial
                else
                {
                    // account for displacement factor
                    ans += line[stnLn[l]][(posInLn[l] + line[stnLn[l]].size() - disp[stnLn[l]]) % line[stnLn[l]].size()];
                    l++;
                }
            }
            cout << ans << '\n';
        }
        // run
        else
        {
            cin >> x;
            int lineStn = line[x].size();
            // displacement factor
            disp[x]++;
            disp[x] %= lineStn;
            for (int i = 0; i < rangeSize; i++)
            {
                // this group isn't in line x
                if (ranges[i].left[x] == INF)
                {
                    continue;
                }
                // update sliding window and left+right position
                ranges[i].np -= line[x][ranges[i].right[x]];
                ranges[i].right[x] = (lineStn + ranges[i].right[x] - 1) % lineStn;
                ranges[i].left[x] = (lineStn + ranges[i].left[x] - 1) % lineStn;
                ranges[i].np += line[x][ranges[i].left[x]];
            }
        }
    }
}