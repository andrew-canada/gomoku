#include <iostream>
#include <algorithm>

using namespace std;

//#define LOCAL

int pieceLengths[2001];

int main()
{
    ios_base::sync_with_stdio(false);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    int numWoodPieces;
    cin >> numWoodPieces;
    int length;
    int maxLength = 1;
    int tempMaxLength = 0;
    int numCombinations = 0;
    for (int i = 0; i < numWoodPieces; i++)
    {
        cin >> length;
        pieceLengths[length] += 1;
    }

    for (int i = 2; i <= 4000; i++)
    {
        tempMaxLength = 0;
        for (int j = 1; j <= i / 2; j++)
        {
            if (i - j <= 2000)
            {
                if (j == i / 2.0)
                {
                    tempMaxLength += pieceLengths[j] / 2;
                }
                else
                {
                    tempMaxLength += min(pieceLengths[j], pieceLengths[i - j]);
                }
            }
        }
        if (tempMaxLength > maxLength)
        {
            maxLength = tempMaxLength;
            numCombinations = 1;
        }
        else if (tempMaxLength == maxLength)
        {
            numCombinations += 1;
        }
    }
    cout << maxLength << " " << numCombinations;
}