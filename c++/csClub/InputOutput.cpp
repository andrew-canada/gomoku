#include <iostream>
using namespace std;

/*
cin is slow
scanf() is fast - 15mb
getchar() and fread are fast but need to self write code
*/

int main()
{
    // cin and cout
    // faster, but can't mix cin with stdio. False and nullptr both = 0;
    cin.sync_with_stdio(0);
    cin.tie(0);
    int a, b;
    cin >> a >> b;
    cout << a << " " << b << endl;

    // scanf()
    int a1, b1;
    scanf("%d");

// getchar()
// returns single character of input. needs to self write function
#define gc getchar()
    //template <typename T>
    //void scan(T & x)
    //{
    //}

    // fread()
    // fastest method, but needs to self write function
    // reads large portion of input and puts into char array
    // better than getchar and putchar
}