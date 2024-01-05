#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

int freq[200];

int main()
{
    string s;
    cin >> s;
    for (char c : s)
    {
        freq[c]++;
    }
    int numOdd = 0;
    for (int i = 'A'; i <= 'Z'; i++)
    {
        if (freq[i] & 1)
        {
            numOdd++;
        }
    }
    if (numOdd > 1)
    {
        cout << "NO SOLUTION\n";
        return 0;
    }
    for (int i = 'A'; i <= 'Z'; i++)
    {
        if (freq[i] % 2 == 0)
        {
            for (int j = 0; j < freq[i] / 2; j++)
            {
                cout << char(i);
            }
        }
    }
    for (int i = 'A'; i <= 'Z'; i++)
    {
        if (freq[i] & 1)
        {
            for (int j = 0; j < freq[i]; j++)
            {
                cout << char(i);
            }
        }
    }
    for (int i = 'Z'; i >= 'A'; i--)
    {
        if (freq[i] % 2 == 0)
        {
            for (int j = 0; j < freq[i] / 2; j++)
            {
                cout << char(i);
            }
        }
    }
}