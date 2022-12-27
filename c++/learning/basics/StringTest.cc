//#include <stdio.h>
#include <iostream>
#include <string.h>
#include <string>
using namespace std;

string findSubstring(const string &sentence, string word);
int countNumberOfWordInString(string sentence, string word);

int main()
{
    string s1 = "hello world";
    // cout << s1.find('w') << endl;
    // cout << s1.find('l') << endl;
    // cout << s1.find('a') << endl;
    // cout << string::npos << endl;
    // cout << s1.find("hello w") << endl;
    // cout << s1.find(" w") << endl;

    // cout << s1.substr(5) << endl;
    // cout << s1.substr(5, 2) << endl;

    cout << findSubstring(s1, "lo") << endl;
    cout << findSubstring(s1, " ") << endl;
    cout << findSubstring(s1, "l") << endl;
    cout << findSubstring(s1, "k") << endl;

    cout << countNumberOfWordInString("hello wo wo wo wo", "wo") << endl;
    cout << countNumberOfWordInString("hello wo wo wo wo", "p") << endl;

    char originalString[] = "aljfd:-)aldjs";
    char strToSearch[] = ":-)";
    cout << "search string in string: " << strstr(originalString, strToSearch) << endl;
}

string findSubstring(const string &sentence, string word)
{

    int index = sentence.find(word);
    if (index != string::npos)
    {
        cout << sentence.substr(index) << endl;
        return sentence.substr(index);
    }
    else
    {
        cout << "not found, return null" << endl;
        return "NULL";
    }
}

int countNumberOfWordInString(string sentence, string word)
{
    int index = sentence.find(word);

    if (index == string::npos)
    {
        return 0;
    }
    return 1 + countNumberOfWordInString(sentence.substr(index + word.length()), word);
}
