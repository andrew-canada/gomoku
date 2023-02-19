#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

//#define LOCAL

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    int maxOrMin;
    int numCitizens;
    int answer = 0;

    scanf("%d\n%d", &maxOrMin, &numCitizens);

    int *dCitizens = new int[numCitizens];
    int *pCitizens = new int[numCitizens];

    for (int i = 0; i < numCitizens; i++)
    {
        scanf("%d", &dCitizens[i]);
    }
    for (int i = 0; i < numCitizens; i++)
    {
        scanf("%d", &pCitizens[i]);
    }

    if (maxOrMin == 1)
    {
        // min
        sort(dCitizens, dCitizens + numCitizens);
        sort(pCitizens, pCitizens + numCitizens);
    }
    else
    {
        sort(dCitizens, dCitizens + numCitizens);
        sort(pCitizens, pCitizens + numCitizens, greater<int>());
    }

    for (int i = 0; i < numCitizens; i++)
    {
        answer += max(dCitizens[i], pCitizens[i]);
    }

    printf("%d", answer);
}