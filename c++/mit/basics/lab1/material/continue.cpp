#include <iostream>

using namespace std;

int main()
{
    for (int i = 0; i <= 10; ++i)
    {
        if (i % 2 != 0)

            // skips all odd numbers - goes back to for loop each time
            continue;

        // prints all even numbers because odds were skipped
        cout << i << "\n";
    }
}