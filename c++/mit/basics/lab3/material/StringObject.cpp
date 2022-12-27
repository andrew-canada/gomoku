#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s = "Hello ";
    s += "world!";
    if (s == "Hello world!")
    {
        cout << "Success!" << endl;
    }
    cout << s.substr(6, 6) << endl; // Prints "world!"
    cout << s.find("H") << endl;
    cout << s.find("world") << endl; // (prints "6")
    // specifies starting location for search
    cout << s.find("l", 5) << endl; // (prints "9")
}