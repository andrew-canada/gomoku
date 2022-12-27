#include <iostream>
#include <unordered_set>
#include <string>

using namespace std;

int main()
{
    std::ios_base::sync_with_stdio(false);

    unordered_set<string> coords;

    // insert().second is true (can insert, no duplicates) or false
    // true : 1
    cout << coords.insert("7, -7").second << '\n';
    // false : 0
    cout << coords.insert("7, -7").second;
}