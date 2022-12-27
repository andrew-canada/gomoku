#include <iostream>
#include <stdio.h>
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
    char group[1000000];
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
    cin >> mustPairList.numberOfGroups;
    mustPairList.membersPerGroup = 2;
    int character = 0, counter = 0, nameLength = 0;
    for (int i = 0; i < mustPairList.membersPerGroup * mustPairList.numberOfGroups; i += 2)
    {
        do
        {
            character = getchar();
            if (character == ' ')
            {
                nameLength = 0;
                continue;
            }
            else
            {
                mustPairList.group[counter] = character;
                nameLength += 1;
            }
            cout << mustPairList.group[counter];
            counter += 1;
        } while (character != '\n');
    }

    // cin >> mustSeparateList.numberOfGroups;
    // mustSeparateList.membersPerGroup = 2;
    // for (int i = 0; i < mustSeparateList.membersPerGroup * mustSeparateList.numberOfGroups; i += 2)
    // {
    //     int character = 0, counter = 0;
    //     do
    //     {
    //         character = getchar();
    //         mustSeparateList.group[counter] = character;
    //         counter += 1;
    //     } while (character != ' ');
    //     do
    //     {
    //         character = getchar();
    //         mustSeparateList.group[counter] = character;
    //         counter += 1;
    //     } while (character != ' ');
    // }

    // cin >> groupsList.numberOfGroups;
    // groupsList.membersPerGroup = 3;
    // for (int i = 0; i < groupsList.membersPerGroup * groupsList.numberOfGroups; i += 3)
    // {
    //     int character = 0, counter = 0;
    //     do
    //     {
    //         character = getchar();
    //         groupsList.group[counter] = character;
    //         counter += 1;
    //     } while (character != ' ');
    //     do
    //     {
    //         character = getchar();
    //         groupsList.group[counter] = character;
    //         counter += 1;
    //     } while (character != ' ');
    //     do
    //     {
    //         character = getchar();
    //         groupsList.group[counter] = character;
    //         counter += 1;
    //     } while (character != ' ');
    // }

    // int numViolations = numRestrictions(&groupsList, &mustPairList, P);
    // cout << numViolations + numRestrictions(&groupsList, &mustSeparateList, S);
}