#include <iostream>
#include <string>

using namespace std;

enum restrictionType
{
    P, // pair
    S  // separate
};

struct List
{
    int numberOfGroups;
    int membersPerGroup;
    string *group;
} mustPairList, mustSeparateList, groupsList;

bool isRestricted(List *inputGroupList, int groupNum, int memberNum, List *inputRestrictionList, int restrictionNum)
{
    return (inputGroupList->group[3 * groupNum + memberNum] == inputRestrictionList->group[restrictionNum] || inputGroupList->group[3 * groupNum + memberNum] == inputRestrictionList->group[restrictionNum + 1]);
}

int numRestrictions(List *inputGroupList, List *inputRestrictionList, char pairOrSeparate)
{
    int mustPair = 0;
    int mustSeparate = 0;
    int numViolations = 0;
    for (int restrictionNum = 0; restrictionNum < 2 * inputRestrictionList->numberOfGroups; restrictionNum += 2)
    {
        bool isViolated = false;
        for (int groupNum = 0; groupNum < inputGroupList->numberOfGroups; groupNum++)
        {
            for (int memberNum = 0; memberNum < 3; memberNum++)
            {
                if (isRestricted(inputGroupList, groupNum, memberNum, inputRestrictionList, restrictionNum))
                {
                    if (pairOrSeparate == P)
                    {
                        mustPair += 1;
                    }
                    if (pairOrSeparate == S)
                    {
                        mustSeparate += 1;
                    }
                }
            }
            if (pairOrSeparate == S && !isViolated)
            {
                if (mustSeparate == 2)
                {
                    numViolations += 1;
                    isViolated = true;
                }
            }
            if (pairOrSeparate == P && !isViolated)
            {
                if (mustPair > 0 && mustPair < 2)
                {
                    numViolations += 1;
                    isViolated = true;
                }
            }
            mustPair = 0;
            mustSeparate = 0;
        }
    }
    return numViolations;
}

int main()
{
    // cin.tie(nullptr);
    // ios::sync_with_stdio(false);
    cin >> mustPairList.numberOfGroups;
    mustPairList.membersPerGroup = 2;
    string *mustPair = new string[2 * mustPairList.numberOfGroups];
    for (int i = 0; i < mustPairList.membersPerGroup * mustPairList.numberOfGroups; i += 2)
    {
        cin >> mustPair[i] >> mustPair[i + 1];
    }
    mustPairList.group = mustPair;

    cin >> mustSeparateList.numberOfGroups;
    mustSeparateList.membersPerGroup = 2;
    string *mustSeparate = new string[2 * mustSeparateList.numberOfGroups];
    for (int i = 0; i < mustSeparateList.membersPerGroup * mustSeparateList.numberOfGroups; i += 2)
    {
        cin >> mustSeparate[i] >> mustSeparate[i + 1];
    }
    mustSeparateList.group = mustSeparate;

    cin >> groupsList.numberOfGroups;
    groupsList.membersPerGroup = 3;
    string *groups = new string[3 * groupsList.numberOfGroups];
    for (int i = 0; i < groupsList.membersPerGroup * groupsList.numberOfGroups; i += 3)
    {
        cin >> groups[i] >> groups[i + 1] >> groups[i + 2];
    }
    groupsList.group = groups;

    int numViolations = numRestrictions(&groupsList, &mustPairList, P);
    cout << numViolations + numRestrictions(&groupsList, &mustSeparateList, S);
}