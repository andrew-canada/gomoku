#include <stdio.h>
#include <string>
#include <algorithm>

int main()
{
    std::string c;
    int numVotes;
    int aCount = 0, bCount = 0;
    scanf("%d", &numVotes);

    getchar();

    for (int i = 0; i < numVotes; i++)
    {
        c.push_back(getchar());
    }
    aCount = count(c.begin(), c.end(), 'A');
    bCount = count(c.begin(), c.end(), 'B');

    if (aCount == bCount)
    {
        puts("Tie");
    }
    else if (aCount > bCount)
    {
        puts("A");
    }
    else
    {
        puts("B");
    }
}