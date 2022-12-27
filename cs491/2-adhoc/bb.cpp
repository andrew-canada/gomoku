#include <vector>
#include <iostream>

using namespace std;

void bin(long n)
{
    long i;
    cout << "0";
    for (i = 1 << 2; i > 0; i = i / 2)
    {
        if ((n & i) != 0)
        {
            cout << "1";
        }
        else
        {
            cout << "0";
        }
    }
}

class Solution
{
public:
    int numberWays(vector<vector<int>> &hats)
    {
        // n: number of persons, 10 at most
        // h: number of hats, 40 at most
        // Time Complexity: O(2^n * h * n)
        // Space Complexity: O(2^n)
        // from the complexity analysis, you can also see why re-organization is critical in passing OJ

        vector<vector<int>> persons(40);
        const int n(hats.size()), mod(1e9 + 7);

        // masks range from 00...0 to 11...1 (n-digit binary number)
        // i-th digit represents whether i-th person has already had a hat
        // Base case: no one has a hat at first
        vector<int> masks(1 << n);
        masks[0] = 1;

        // re-organize, hats -> persons
        for (int i = 0; i < n; ++i)
            for (const int &h : hats[i])
                persons[h - 1].emplace_back(i);

        for (int i = 0; i < 40; ++i)                // hats
            for (int j = (1 << n) - 1; j >= 0; --j) // masks
                for (const int &p : persons[i])     // persons
                                                    // if the current state j implies that p-th person hasn't had a hat yet
                                                    // we can give the i-th hat to that person, and update the state
                    if ((j & (1 << p)) == 0)
                    {
                        cout << "j: " << j << " mask[j]:" << masks[j];
                        masks[j | (1 << p)] += masks[j];
                        masks[j | (1 << p)] %= mod;
                        cout << "hat:" << i << " mask:";
                        bin(j);
                        cout << " person:";
                        bin(p);
                        cout << " current bit:";
                        bin(j | (1 << p));
                        cout << " value of current bit:" << masks[j | (1 << p)] << "\n";
                        cout << " p: " << p << " mask[j]:" << masks[j] << "\n";
                    }
        // return the state that each person has a hat
        return masks[(1 << n) - 1];
    }
};

int main()
{
    Solution solution;
    vector<vector<int>> hats{{1, 2, 3, 4, 5, 6, 7}, {1}};
    cout << solution.numberWays(hats);
}