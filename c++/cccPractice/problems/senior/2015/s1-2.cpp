#include <stdio.h>
#include <vector>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

int k;
vector<int> n;
int val;
int sum;

int main()
{
    scanf("%d", &k);
    REP(i, 0, k)
    {
        scanf("%d", &val);
        if (val == 0)
        {
            n.pop_back();
        }
        else
        {
            n.push_back(val);
        }
    }
    for (int num : n)
    {
        sum += num;
    }
    printf("%d", sum);
}