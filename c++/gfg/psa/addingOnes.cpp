#include <bits/stdc++.h>

using namespace std;

int arr[3];

void update(int idx);

int main()
{
    update(1);
    update(1);
    update(2);
    update(3);
    int sum = 0;
    for (int i = 0; i < 3; i++)
    {
        sum += arr[i];
        cout << sum << ' ';
    }
}

void update(int idx)
{
    arr[idx - 1]++;
}