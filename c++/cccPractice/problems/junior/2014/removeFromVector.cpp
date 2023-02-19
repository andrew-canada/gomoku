#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main()
{
    vector<string> names = {"a", "b", "c", "d"};
    auto it = find(names.begin(), names.end(), "c");
    cout << it - names.begin() + 1;
    names.erase(it);
    for_each(names.begin(), names.end(), [](string element)
             { cout << element; });
}