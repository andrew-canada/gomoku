/*
write c++ code to solve this problem:
sub-message sum (SMS). Given a binary string of length N, and some positive integer K with K≤N, the SMS for
the string consists of a sequence of N−K+ 1 sums. The first sum in the sequence is the
sum of digits 1 through K, the second sum is the sum of digits 2 through K+ 1, and so on
until the last sum which is the sum of digits N−K+ 1 through N.
For example, if K= 4, the SMS of the binary string 110010 is 2,2,1. This is because
1 + 1 + 0 + 0 = 2, 1 + 0 + 0 + 1 = 2, and 0 + 0 + 1 + 0 = 1.
the code needs to find  the number of binary strings that could have formed this SMS.

Input Specification: The first line of input contains the two space-separated integers
N and K where 1<=K<=n. The second line of input contains N−K+ 1 space-separated integers
which is the SMS of at least one binary string.

Output Specification: Output the remainder of T divided by the prime number 10^6+3 where T
 is the positive integer equal to the total number of possible binary strings that correspond to the given SMS.

*/
#include <iostream>
#include <vector>
using namespace std;

const int MOD = 1000003; // the prime number to take modulo

// a function to calculate the number of ways to form a binary string of length n with k ones
int binom(int n, int k)
{
    // use dynamic programming to avoid overflow
    vector<vector<int>> dp(n + 1, vector<int>(k + 1, 0));
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= min(i, k); j++)
        {
            if (j == 0 || j == i)
            {
                dp[i][j] = 1; // base case: n choose 0 or n choose n is 1
            }
            else
            {
                dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j]) % MOD; // recurrence: n choose k is (n-1) choose (k-1) plus (n-1) choose k
            }
        }
    }
    return dp[n][k];
}

// a function to count the number of binary strings that have the given SMS
int count_strings(vector<int> &sms, int n, int k)
{
    int ans = 1;       // initialize the answer to 1
    int ones = sms[0]; // the number of ones in the first k digits
    for (int i = 1; i < sms.size(); i++)
    {
        int diff = sms[i] - sms[i - 1]; // the difference between the current and previous sums
        if (diff == 0)
        {
            // no change in the number of ones, so multiply the answer by 2
            ans = (ans * 2) % MOD;
        }
        else if (diff == 1)
        {
            // one more one in the current k digits, so multiply the answer by the number of ways to choose a zero to flip
            ans = (ans * (k - ones)) % MOD;
            ones++; // increment the number of ones
        }
        else if (diff == -1)
        {
            // one less one in the current k digits, so multiply the answer by the number of ways to choose a one to flip
            ans = (ans * ones) % MOD;
            ones--; // decrement the number of ones
        }
        else
        {
            // the difference is more than 1 or less than -1, which means there is no binary string that can have this SMS
            return 0;
        }
    }
    return ans;
}

int main()
{
    int n, k;                   // the length of the binary string and the size of the sub-message
    cin >> n >> k;              // read the input
    vector<int> sms(n - k + 1); // the vector to store the SMS
    for (int i = 0; i < n - k + 1; i++)
    {
        cin >> sms[i]; // read the SMS
    }
    int t = count_strings(sms, n, k); // the number of binary strings that have the given SMS
    if (t == 0)
    {
        // there is no binary string that can have this SMS
        cout << 0 << endl;
    }
    else
    {
        // there are some binary strings that can have this SMS, so multiply the answer by the number of ways to choose the ones in the first k digits
        int first = sms[0];    // the number of ones in the first k digits
        int last = sms.back(); // the number of ones in the last k digits
        if (first == last)
        {
            // the first and the last digits are the same, so the number of ways is binom(k, first)
            cout << (t * binom(k, first)) % MOD << endl;
        }
        else
        {
            // the first and the last digits are different, so the number of ways is binom(k, first) + binom(k, first + 1)
            cout << (t * (binom(k, first) + binom(k, first + 1))) % MOD << endl;
        }
    }
    return 0;
}
