#include <iostream>
#include <vector>

using namespace std;

int count_possible_strings(int N, int K, const vector<int> &sums)
{
    int total_sum = 0;
    for (int sum : sums)
    {
        total_sum += sum;
    }

    int count = 0;
    vector<int> differences(N, 0);

    differences[0] = sums[0];
    for (int i = 1; i < N; ++i)
    {
        differences[i] = sums[i] - sums[i - 1];
    }

    int last_sum = 0;
    for (int i = 0; i < N; ++i)
    {
        if (i >= K)
        {
            last_sum -= differences[i - K];
        }
        last_sum += differences[i];

        if ((i < K - 1 && last_sum == 0) || (i >= K - 1 && last_sum == total_sum))
        {
            count++;
        }
    }

    return count;
}

int main()
{
    // Sample Input 1
    int N1 = 1;
    int K1 = 1;
    vector<int> sums1 = {0};
    int result1 = count_possible_strings(N1, K1, sums1);
    cout << result1 << endl; // Output: 1

    // Sample Input 2
    int N2 = 10;
    int K2 = 3;
    vector<int> sums2 = {1, 2, 2, 2, 2, 2, 2, 2};
    int result2 = count_possible_strings(N2, K2, sums2);
    cout << result2 << endl; // Output: 2

    // Sample Input 3
    int N3 = 10;
    int K3 = 3;
    vector<int> sums3 = {2, 2, 2, 2, 2, 2, 2, 2};
    int result3 = count_possible_strings(N3, K3, sums3);
    cout << result3 << endl; // Output: 3

    return 0;
}
