#include <stdio.h>
#include <vector>
#include <cstring>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MIN(a, b) ((a) < (b) ? (a) : (b))

char seats[1000005];
int psa[3][1000005];
int swaps = 0;
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
    getSwaps(0, 1, 2);
    printf("%d", swaps);
}

int getPeople(int g, int s1, int len)
{
    return psa[g][s1 + len] - psa[g][s1];
}

void getSwaps(int a, int b, int c)
{
    int sAB = 1000005, sAC = 1000005;
    int totA = psa[a][n];
    int totB = psa[b][n];
    int totC = psa[c][n];

    REP(i, 0, n - totA - totB)
    {
        int nonAinA = totA - getPeople(a, i, totA);
        int nonBinB = totB - getPeople(b, i + totA, totB);
        int BinA = getPeople(b, i, totA);
        int AinB = getPeople(a, i + totA, totB);
        sAB = MIN(sAB, nonAinA + nonBinB - MIN(BinA, AinB));
    }
    REP(i, 0, n - totA - totC)
    {
        int nonAinA = totA - getPeople(a, i, totA);
        int nonCinC = totC - getPeople(c, i + totA, totC);
        int CinA = getPeople(c, i, totA);
        int AinC = getPeople(a, i + totA, totC);
        sAC = MIN(sAC, nonAinA + nonCinC - MIN(CinA, AinC));
    }
    swaps = MIN(sAB, sAC);
}