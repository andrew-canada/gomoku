#include <iostream>
#include <queue>

using namespace std;

//#define LOCAL
bool visitedPositions[10000000];

int main()
{
    ios_base::sync_with_stdio(false);
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
    // freopen("out.txt", "w", stdout);
#endif
    int numRows, numColumns;
    cin >> numRows >> numColumns;
    int *matrix = new int[(numRows + 1) * (numColumns + 1)];
    queue<int> path;
    int currentValue = 0;
    int newVal = 0;

    for (int i = 1; i <= numRows; i++)
    {
        for (int j = 1; j <= numColumns; j++)
        {
            cin >> matrix[(i - 1) * numColumns + j];
        }
    }

    path.push(matrix[1]);
    while (!path.empty())
    {
        currentValue = path.front();
        path.pop();
        if (!visitedPositions[currentValue])
        {
            visitedPositions[currentValue] = true;
            for (int i = 1; i * i <= currentValue; i++)
            {
                if (currentValue % i == 0)
                {
                    newVal = currentValue / i;
                    if ((i <= numRows && newVal <= numColumns))
                    {
                        int nextValue = matrix[(i - 1) * numColumns + newVal];
                        if (!visitedPositions[nextValue])
                        {
                            path.push(nextValue);
                        }
                    }
                    if (i <= numColumns && newVal <= numRows)
                    {
                        int nextValue = matrix[(newVal - 1) * numColumns + i];
                        if (!visitedPositions[nextValue])
                        {
                            path.push(nextValue);
                        }
                    }
                    if ((i == numColumns && newVal == numRows) || (i == numRows && newVal == numColumns))
                    {
                        cout << "yes";
                        return 0;
                    }
                }
            }
        }
    }
    cout << "no";
    return 0;
}