#include <iostream>
using namespace std;

int main()
{
    int numOfVotes = 0;
    string votes;
    cin >> numOfVotes >> votes;
    int aCount = 0, bCount = 0;

    for (int i = 0; i < numOfVotes; i++)
    {
        if (votes[i] == 'A')
        {
            aCount += 1;
        }
        else
        {
            bCount += 1;
        }
    }
    if (aCount > bCount)
    {
        cout << "A";
    }
    else if (bCount > aCount)
    {
        cout << "B";
    }
    else
    {
        cout << "Tie";
    }
    return 0;
}