/*
n station [1, n]
w walkway from a to b, 1 minute
1 minute to adjacent station
d days
each day, random station s1[2, n] will swap with a station s2[2, n]
e.g., s1=2, s2=3 --> swap 2nd station with 3rd station
1-indexed
s1 != s2
updates occur immediately upon the beginning of a new day
find min walkTime to get from station 1 to station n
3 choices each minute:
1. train
2. walkway
3. wait at station
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define pb push_back
#define INF 0x3f3f3f3f

vector<int> walk[200005];
int stn[200005];
int vis[200005];
int walkTime[200005];
int stnPos[200005];
queue<int> q;
multiset<int> optTime;

int main()
{
    // 1. all train
    // 2. walk + train, only leave train once
    memset(walkTime, INF, sizeof(walkTime));
    int n, w, d;
    scanf("%d%d%d", &n, &w, &d);
    int a, b;
    REP(i, 1, w)
    {
        scanf("%d%d", &a, &b);
        walk[b].pb(a);
    }
    int cur;
    q.push(n);
    vis[n] = true;
    walkTime[n] = 0;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        for (int st : walk[cur])
        {
            if (!vis[st])
            {
                vis[st] = true;
                q.push(st);
                walkTime[st] = walkTime[cur] + 1;
            }
        }
    }
    REP(i, 1, n)
    {
        scanf("%d", &stn[i]);
        stnPos[stn[i]] = i - 1;
    }
    REP(i, 1, n)
    {
        optTime.insert(stnPos[i] + walkTime[i]);
    }
    int n1, n2, s1, s2;
    REP(i, 1, d)
    {
        scanf("%d%d", &n1, &n2);
        s1 = stn[n1], s2 = stn[n2];
        optTime.erase(optTime.find(stnPos[s1] + walkTime[s1]));
        optTime.erase(optTime.find(stnPos[s2] + walkTime[s2]));
        swap(stnPos[s1], stnPos[s2]);
        swap(stn[n1], stn[n2]);
        optTime.insert(stnPos[s1] + walkTime[s1]);
        optTime.insert(stnPos[s2] + walkTime[s2]);
        printf("%d\n", *optTime.begin());
    }
}