#include <stdio.h>
#include <cstring>
#include <algorithm>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

int getPeople(int g, int s1, int numP);
void calcSwaps(int a, int b, int c);

char seats[1000005];
int n;
int psa[3][1000005];
int groups[3] = {0, 1, 2};
int swaps = 1000005;

int main()
{
    scanf("%s", &seats);
    n = strlen(seats);
    REP(i, 0, 2)
    {
        REP(j, 1, n)
        {
            psa[i][j] = psa[i][j - 1] + (seats[j - 1] == (i + 'A'));
        }
    }
    do
    {
        calcSwaps(groups[0], groups[1], groups[2]);
    } while (next_permutation(groups, groups + 3));
    printf("%d", swaps);
}

int getPeople(int g, int s1, int numP)
{
    return psa[g][s1 + numP] - psa[g][s1];
}

void calcSwaps(int a, int b, int c)
{
    int totA = psa[a][n];
    int totB = psa[b][n];
    int totAB = totA + totB;

    int numA, numB, numC;
    int misA, misB;
    int AinA, BinB, CinA, CinB;
    REP(i, 0, n - totAB)
    {
        numA = getPeople(a, i, totAB);
        numB = getPeople(b, i, totAB);
        numC = getPeople(c, i, totAB);
        misA = totA - numA;
        misB = totB - numB;
        AinA = getPeople(a, i, totA);
        BinB = getPeople(b, i, totB);
        CinA = getPeople(c, i, totA);
        CinB = getPeople(c, i, totB);
        swaps = min(swaps, numC + min(totA - (AinA + min(misA, CinA)), totB - (BinB + min(misB, CinB))));
    }
}