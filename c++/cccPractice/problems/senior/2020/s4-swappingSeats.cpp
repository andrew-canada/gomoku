#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

string seats;
vector<int> groups = {0, 1, 2};
int psa[3][1000005];
int swaps = 0;
int n = 0;

void getSwaps(int a, int b, int c);
int getPeople(int g, int s1, int len);

int main()
{
    ios_base::sync_with_stdio(false);
    cin >> seats;
    n = seats.size();
    REP(i, 0, 2)
    {
        psa[i][0] = 0;
        REP(j, 1, n)
        {
            psa[i][j] = psa[i][j - 1] + (seats[j - 1] - 'A' == i);
        }
    }
    do
    {
        getSwaps(groups[0], groups[1], groups[2]);
    } while (next_permutation(groups.begin(), groups.end()));
    cout << swaps;
}

int getPeople(int g, int s1, int len)
{
    return psa[g][s1 + len] - psa[g][s1];
}

void getSwaps(int a, int b, int c)
{
    int totA = psa[a][n];
    int totB = psa[b][n];
    int ab = totA + totB;
    REP(i, 0, ab - totB)
    {
        int na = getPeople(a, i, ab);
        int nb = getPeople(b, i, ab);
        int nc = getPeople(c, i, ab);
        int remA = totA - na, remB = totB - nb;

        int curA = getPeople(a, i, totA);
        int curB = getPeople(b, i, totB);
    }
}