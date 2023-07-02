#include <stdio.h>
#include <stack>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

int t, n;
int unordCar, prevUnordCar;
int cars[100005];
stack<int> unord;

int main()
{
    scanf("%d", &t);
    REP(i, 0, t)
    {
        scanf("%d", &n);
        int numOrd = 0;
        int curCar = 1;
        for (int i = n - 1; i >= 0; i--)
        {
            scanf("%d", &cars[i]);
        }
        REP(i, 0, n)
        {
            bool isCurOrd = false;
            if (cars[i] == curCar)
            {
                curCar++;
                numOrd++;
                isCurOrd = true;
            }
            while (!unord.empty())
            {
                if (unord.top() == curCar)
                {
                    curCar++;
                    unord.pop();
                    numOrd++;
                }
                else
                {
                    break;
                }
            }
            if (!isCurOrd)
            {
                unord.push(cars[i]);
            }
        }
        numOrd == n ? printf("Y\n") : printf("N\n");
    }
}