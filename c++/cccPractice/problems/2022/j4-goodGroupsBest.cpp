#include <iostream>
#include <string>
#include <map>

using namespace std;

string same1[100001], same2[100001], diff1[100001], diff2[100001];

int main()
{
    ios_base::sync_with_stdio(false);
    int numSamePair;
    cin >> numSamePair;

    for (int i = 0; i < numSamePair; i++)
    {
        cin >> same1[i] >> same2[i];
    }

    int numDiffPair;
    cin >> numDiffPair;

    for (int i = 0; i < numDiffPair; i++)
    {
        cin >> diff1[i] >> diff2[i];
    }

    int numGroups;
    cin >> numGroups;
    map<string, int> groups;
    string m1, m2, m3;
    for (int i = 0; i < numGroups; i++)
    {
        cin >> m1 >> m2 >> m3;
        groups[m1] = i;
        groups[m2] = i;
        groups[m3] = i;
    }

    int numViolations = 0;
    for (int i = 0; i < numSamePair; i++)
    {
        if (groups[same1[i]] != groups[same2[i]])
        {
            numViolations += 1;
        }
    }

    for (int i = 0; i < numDiffPair; i++)
    {
        if (groups[diff1[i]] == groups[diff2[i]])
        {
            numViolations += 1;
        }
    }

    cout << numViolations;
}