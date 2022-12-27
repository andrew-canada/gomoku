#include <iostream>
#include <string>

using namespace std;

int main()
{
    string sentence1;
    // reads until first space
    cin >> sentence1;
    cout << sentence1 << endl;

    string sentence2;
    // reads until press enter
    getline(cin, sentence2);
    cout << sentence2 << endl;
}