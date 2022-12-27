#include <iostream>

using namespace std;

int main()
{
    while (1)
    {
        int N;
        cin >> N;
        if (N % 5 > 0)
        {
            cout << "-1\n";
            continue;
        }
        cout << N / 5 << "\n";
    }
    return 0;
}