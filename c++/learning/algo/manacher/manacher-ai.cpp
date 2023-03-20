#include <iostream>
#include <string>
#include <vector>

using namespace std;

string findLongestPalindrome(string s)
{
    string T = "#";
    for (char c : s)
    {
        T += c;
        T += "#";
    }

    int n = T.size();
    vector<int> P(n, 0);
    int C = 0, R = 0;

    for (int i = 1; i < n - 1; i++)
    {
        int mirror = 2 * C - i;
        if (i < R)
        {
            P[i] = min(R - i, P[mirror]);
        }

        while (T[i + (1 + P[i])] == T[i - (1 + P[i])] && i + (1 + P[i]) < n && i - (1 + P[i]) >= 0)
        {
            P[i]++;
        }

        if (i + P[i] > R)
        {
            C = i;
            R = i + P[i];
        }
    }

    int center = 0, len = 0;
    for (int i = 1; i < n - 1; i++)
    {
        if (P[i] > len)
        {
            len = P[i];
            center = i;
        }
    }

    return s.substr((center - len) / 2, len);
}

int main()
{
    string s = "cabaabag";
    string longest_palindrome = findLongestPalindrome(s);
    cout << longest_palindrome << endl;
    return 0;
}
