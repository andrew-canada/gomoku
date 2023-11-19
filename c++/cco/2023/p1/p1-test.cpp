#include <bits/stdc++.h>
#include <vector>

using namespace std;

int calculate_sms(const string &binary_string, int N, int K, vector<int> &sms)
{
    sms.clear();
    for (int i = 0; i <= N - K; ++i)
    {
        int sum = 0;
        for (int j = i; j < i + K; ++j)
        {
            sum += binary_string[j] - '0';
        }
        sms.push_back(sum);
    }
    return 0;
}

bool is_valid(const string &binary_string, int N, int K, const vector<int> &target_sums)
{
    vector<int> sms;
    calculate_sms(binary_string, N, K, sms);
    return sms == target_sums;
}

void generate_binary_strings(int N, vector<string> &binary_strings)
{
    for (int i = 0; i < (1 << N); ++i)
    {
        string binary_string = bitset<32>(i).to_string().substr(32 - N);
        binary_strings.push_back(binary_string);
    }
}

int count_possible_strings(int N, int K, const vector<int> &sums)
{
    vector<string> binary_strings;
    generate_binary_strings(N, binary_strings);

    int count = 0;
    for (const auto &binary_string : binary_strings)
    {
        if (is_valid(binary_string, N, K, sums))
        {
            count++;
        }
    }

    return count;
}

int main()
{
    // Sample Input
    int N = 10;
    int K = 3;
    vector<int> sums = {1, 1, 0, 1, 2, 3, 2, 2};

    // Output
    int result = count_possible_strings(N, K, sums);
    cout << result << endl;

    return 0;
}
