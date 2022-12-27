#include <iostream>
#include <unordered_map>
#include <unordered_set>
#include <string>

using namespace std;

int main()
{
    int numberOfPairs;
    cin >> numberOfPairs;
    unordered_map<string, unordered_set<string>> friendMap;
    string key;
    string value;
    for (int i = 0; i < numberOfPairs; i++)
    {
        cin >> key >> value;

        auto it = friendMap.find(key);
        if (it == friendMap.end())
        {
            unordered_set<string> values;
            values.insert(value);
            unordered_set<string> sendKey;
            sendKey.insert(key);
            friendMap.insert(it, pair<string, unordered_set<string>>(key, values));
            friendMap.insert(it, pair<string, unordered_set<string>>(value, sendKey));
        }
        else
        {
            it->second.insert(value);
            unordered_set<string> sendKey;
            sendKey.insert(key);
            friendMap.insert(it, pair<string, unordered_set<string>>(value, sendKey));
        }
    }

    cin >> numberOfPairs;
    unordered_map<string, unordered_set<string>> enemyMap;
    for (int i = 0; i < numberOfPairs; i++)
    {
        cin >> key >> value;

        auto it = enemyMap.find(key);
        if (it == enemyMap.end())
        {
            unordered_set<string> values;
            values.insert(value);
            unordered_set<string> sendKey;
            sendKey.insert(key);
            enemyMap.insert(it, pair<string, unordered_set<string>>(key, values));
            enemyMap.insert(it, pair<string, unordered_set<string>>(value, sendKey));
        }
        else
        {
            it->second.insert(value);
            unordered_set<string> sendKey;
            sendKey.insert(key);
            enemyMap.insert(it, pair<string, unordered_set<string>>(value, sendKey));
        }
    }

    int numberOfGroups;
    cin >> numberOfGroups;

    string n1, n2, n3;
    int violationCount = 0;
    for (int i = 0; i < numberOfGroups; i++)
    {
        cin >> n1 >> n2 >> n3;
        unordered_set<string> group;
        group.insert(n1);
        group.insert(n2);
        group.insert(n3);

        for (auto &j : group)
        {
            if (enemyMap.find(j) != enemyMap.end())
            {
                // loop unordered_set value and see if it is found in group
                unordered_set<string>::const_iterator it;
                unordered_set<string> currentSet = enemyMap.find(j)->second;
                for (it = currentSet.begin(); it != currentSet.end(); it++)
                {
                    if (group.find(*it) != group.end())
                    {
                        enemyMap.find(*it)->second.erase(j);
                        enemyMap.find(j)->second.erase(*it);
                        violationCount += 1;
                    }
                }
            }
            if (friendMap.find(j) != friendMap.end())
            {
                // loop unordered_set value and see if it is found in group
                unordered_set<string>::const_iterator it;
                unordered_set<string> currentSet = friendMap.find(j)->second;
                for (it = currentSet.begin(); it != currentSet.end(); it++)
                {
                    if (group.find(*it) == group.end())
                    {
                        friendMap.find(*it)->second.erase(j);
                        friendMap.find(j)->second.erase(*it);
                        violationCount += 1;
                    }
                }
            }
        }
    }
    cout << violationCount;
}
