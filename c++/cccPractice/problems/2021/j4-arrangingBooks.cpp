#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    int numL = 0, numM = 0;
    int numMInL = 0, numLInM = 0;
    int numNonLInL = 0, numNonMInM = 0;
    char input[500'001];
    cin >> input;

    for (int i = 0; i < strlen(input); i++)
    {
        if (input[i] == 'L')
        {
            numL += 1;
        }
        else if (input[i] == 'M')
        {
            numM += 1;
        }
    }

    for (int i = 0; i < numL; i++)
    {
        if (input[i] == 'M')
        {
            numMInL += 1;
            numNonLInL += 1;
        }
        else if (input[i] != 'L')
        {
            numNonLInL += 1;
        }
    }

    for (int i = numL; i < numL + numM; i++)
    {
        if (input[i] == 'L')
        {
            numLInM += 1;
            numNonMInM += 1;
        }
        else if (input[i] != 'M')
        {
            numNonMInM += 1;
        }
    }

    cout << numNonLInL + numNonMInM - std::min(numMInL, numLInM);
}