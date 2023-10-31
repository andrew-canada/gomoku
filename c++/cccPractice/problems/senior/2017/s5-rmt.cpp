// ln 90

#include <stdio.h>
#include <vector>
#include <string>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define INF 0x3f3f3f3f

typedef vector<int> vi;

struct group
{
    int np;
    vi l = vi(150005, INF);
    vi r = vi(150005, INF);
};

int n, m, q;
int psg;
int stnLn[150005];
group groups[388];
int act;
int line, s1, s2;
vector<int> lines[150005];
int shiftAmt[150005];
int pos[150005];

int main()
{
    // freopen("s5.in", "r", stdin);
    // freopen("s5.out", "w", stdout);
    scanf("%d%d%d", &n, &m, &q);
    REP(i, 1, n)
    {
        scanf("%d", &stnLn[i]);
    }
    REP(i, 1, n)
    {
        scanf("%d", &psg);
        lines[stnLn[i]].push_back(psg);
        groups[i / 388].np += psg;
        groups[i / 388].l[stnLn[i]] = MIN(lines[stnLn[i]].size() - 1, groups[i / 388].l[stnLn[i]]);
        groups[i / 388].r[stnLn[i]] = lines[stnLn[i]].size() - 1;
        pos[i] = lines[stnLn[i]].size() - 1;
    }
    while (q--)
    {
        scanf("%d", &act);
        if (act == 1)
        {
            scanf("%d%d", &s1, &s2);
            int numPassenger = 0;
            while (s1 <= s2)
            {
                if (s1 % 388 == 0 && s1 + 388 <= s2)
                {
                    // printf("if|%d\n", s1);
                    numPassenger += groups[s1 / 388].np;
                    s1 += 388;
                }
                else
                {
                    numPassenger += lines[stnLn[s1]][(pos[s1] - shiftAmt[stnLn[s1]] + lines[stnLn[s1]].size()) % lines[stnLn[s1]].size()];
                    s1++;
                }
            }
            printf("%d\n", numPassenger);
        }
        else
        {
            scanf("%d", &line);
            // printf("2|%d\n", line);
            int lineSz = lines[line].size();
            shiftAmt[line]++;
            shiftAmt[line] %= lineSz;
            REP(i, 0, 387)
            {
                if (groups[i].l[line] == INF)
                {
                    continue;
                }
                // printf("|%d %d\n", line, groups[i].r[line]);
                // printf("||%d\n", lines[line][groups[i].r[line]]);
                // printf("ln81\n");
                groups[i].np -= lines[line][groups[i].r[line]];
                // printf("ln83\n");
                groups[i].r[line] = (groups[i].r[line] + lineSz - 1) % lineSz;
                groups[i].l[line] = (groups[i].l[line] + lineSz - 1) % lineSz;
                groups[i].np += lines[line][groups[i].l[line]];
            }
            // printf("2|end\n");
        }
    }
}