#include <iostream>
#include <string>

using namespace std;

const string VOWELS = "a, e, i, o, u";

string pigLatinify(const string &str)
{
    if (str.size() == 0)
    {
        cout << "empty string" << endl;
        return str;
    }
    else if (str.find("qu") == 0)
    {
        return str.substr(2, str.size() - 1) + "-quay";
    }
    else if (VOWELS.find(str[0]) != string::npos)
    {
        return str + "way";
    }
    else
    {
        return str.substr(1, str.size() - 1) + "-" + str[0] + "ay";
    }
}

int main()
{
    cout << pigLatinify("car") << endl;
    cout << pigLatinify("abacus") << endl;
    cout << pigLatinify("quacus") << endl;
    cout << pigLatinify("") << endl;
}