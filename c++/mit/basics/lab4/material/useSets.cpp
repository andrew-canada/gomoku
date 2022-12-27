#include <iostream>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
    // set, set insert, iterator, set.begin()/end(), binary_search
    set<int> id;
    id.insert(1);
    id.insert(2);
    id.insert(3);

    set<int>::iterator it;
    for (it = id.begin(); it != id.end(); it++)
    {
        cout << *it << " ";
    }
    cout << '\n';

    int term;
    cin >> term;
    if (binary_search(id.begin(), id.end(), term))
    {
        cout << "found" << endl;
    }
    else
    {
        cout << "not found" << endl;
    }
}