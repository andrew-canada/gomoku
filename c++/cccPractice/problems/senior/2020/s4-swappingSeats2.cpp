#include <stdio.h>
#include <vector>
#include <cstring>
#include <algorithm>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MIN(a, b) ((a) < (b) ? (a) : (b))

char seats[1000005];
int psa[3][1000005];
int groups[3] = {0, 1, 2};
int swaps = 1000005;
int n = 0;

void getSwaps(int a, int b, int c);
int getPeople(int g, int s1, int len);

int main()
{
    scanf("%s", &seats);
    n = strlen(seats);
    REP(i, 0, 2)
    {
        psa[i][0] = 0;
        REP(j, 1, n)
        {
            psa[i][j] = psa[i][j - 1] + (seats[j - 1] == 'A' + i);
        }
    }
    do
    {
        getSwaps(groups[0], groups[1], groups[2]);
    } while (next_permutation(groups, groups + 3));
    printf("%d", swaps);
}

int getPeople(int g, int s1, int len)
{
    return psa[g][s1 + len] - psa[g][s1];
}

void getSwaps(int a, int b, int c)
{
    int totA = psa[a][n];
    int totB = psa[b][n];
    int totAB = totA + totB;

    REP(i, 0, n - totAB)
    {
        int numA = getPeople(a, i, totAB);
        int numB = getPeople(b, i, totAB);
        int numC = getPeople(c, i, totAB);

        int misA = totA - numA;
        int misB = totB - numB;

        int AinA = getPeople(a, i, totA);
        int CinA = getPeople(c, i, totA);
        int BinB = getPeople(b, i, totB);
        int CinB = getPeople(c, i, totB);

        int curSwaps = numC + MIN(totA - (AinA + MIN(misA, CinA)), totB - (BinB + MIN(misB, CinB)));
        swaps = MIN(swaps, curSwaps);
    }
}