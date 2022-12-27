#include <iostream>
#include <vector>

using namespace std;

// recursive vs iterative
// iterative is faster and less memory
// recursive doesn't calculate ALL values so it could be faster

// takeaways
// a game can be represented as a set of finintely many states
// the state of a game will be either winning or losing the
// a state is winning of at least one of the states can be changed to losing

// Number of terms remaining defines the state of the game.

//java: Scanner is very slow
// BufferedReader is inconvient but faster
int n, k;
int arr[100];
bool isWinning[100001];

int main()
{
    // scanf is for reading input. format specifier string %d = decimal. reads as integer.
    // can be %s - string.
    // pointer to value you want to read.
    // scanf is used for reading input (another way is cin)
    // https://dmoj.ca/problem/dpk
    scanf("%d %d", &n, &k);
    for (int i = 0; i < n; i++)
        scanf("%d", arr + i);
    for (int i = 1; i <= k; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (i - arr[j] < 0)
                break;
            if (!isWinning[i - arr[j]])
            {
                isWinning[i] = true;
                break;
            }
        }
    }
    printf(isWinning[k] ? "First\n" : "Second\n");

    // https://dmoj.ca/problem/qccp1
    //27 is 0011011. Index 27 will have colors 0, 1, 3, and 4 visited and 2, 5, and 6 not.

    // bitwise operators convert numbers to binary and does operations.
    // converts 5 and 6 to binary. 0101 & 0110. result is 0100, or 4.
    // cout << (0101 & 0110) << endl;
    cout << (5 & 6) << endl;
    cout << (0101 << 1) << endl;
    cout << (0110 ^ 1010) << endl;

    // bitmask is used for bitwise operation
    // btimask: when we use the bits of an integer to represent something other than a number

    const int MN = 1e5;
    vector<pair<int, int>> adjList[MN];
    int n, m;
    int8_t dp[MN][128];

    // find the longest path in a graph that starts at node 0 and ends at node n-1.
    // visit each node at moast once
    // n is at most once

    // solve with bitmask dynamic programming
    // dp[i][j] is max dist of a pth from node 0 -> node i such that you only went over
    //nodes which have the corresponding bit set in j *max length of a path
}