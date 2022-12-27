#include <iostream>
#define product(x, y) (x * y);

using namespace std;

int main()
{
    // 3 substitutes into x, 4 into y
    cout << product(3, 4);
    // not type-checked - can produce unexpected results if given incompatible types
    cout << product('a', 'b');
}