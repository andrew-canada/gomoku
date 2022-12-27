#include <iostream>
#include <cctype>
#include <cstring>

using namespace std;
int main()
{
    // cctype
    char messyString[] = "t6H0I9s6.iS.999a9.STRING";
    char current = messyString[0];
    for (int i = 0; current != '\0'; current = messyString[++i])
    {
        if (isalpha(current))
            cout << (char)(isupper(current) ? tolower(current) : current);
        else if (ispunct(current))
            cout << ' ';
    }

    cout << endl;

    // cstring
    char fragment1[] = "I'm a s";
    char fragment2[] = "tring!";
    char fragment3[20];
    char finalString[20] = "";

    strcpy(fragment3, fragment1);
    strcat(finalString, fragment3);
    strcat(finalString, fragment2);

    cout << finalString;
    return 0;
}