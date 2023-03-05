#include <stdio.h>
#include <vector>

using namespace std;

vector<int> nums;
int n;
int val;
int tot;

int main()
{
    scanf("%d", &n);
    while (n--)
    {
        scanf("%d", &val);
        if (val == 0)
        {
            nums.pop_back();
        }
        else
        {
            nums.push_back(val);
        }
    }
    for (int num : nums)
    {
        tot += num;
    }
    printf("%d", tot);
}