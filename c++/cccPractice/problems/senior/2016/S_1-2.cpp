#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define pb push_back

typedef long long ll;

const int mxN = 100;

int freqA[200], freqB[200];

int main()
{
    string a, b;
    cin >> a >> b;
    for (char c : a)
    {
        freqA[c]++;
    }
    for (char c : b)
    {
        freqB[c]++;
    }
    for (int i = 'a'; i <= 'z'; i++)
    {
        if (freqB[i] > freqA[i])
        {
            cout << "N";
            return 0;
        }
    }
    cout << "A";
}