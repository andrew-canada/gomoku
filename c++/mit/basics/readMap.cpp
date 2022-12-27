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
    for (auto &val : friendMap)
    {
        cout << val.first << ": ";
        unordered_set<string>::const_iterator it;
        for (it = val.second.begin(); it != val.second.end(); it++)
        {
            cout << *it << " ";
        }
        cout << endl;
    }
}