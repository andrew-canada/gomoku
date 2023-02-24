#include <stdio.h>
#include <utility>
#include <algorithm>

// #define max(a, b) (a > b ? a : b)
// #define abs(a) (a < 0 ? -a : a)

using namespace std;

int n;
double fastest;
pair<int, int> obs[100001];

int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d", &obs[i].first, &obs[i].second);
    }
    sort(obs, obs + n);

    for (int i = 0; i < n; i++)
    {
        fastest = max(fastest, abs(obs[i + 1].second - (double)obs[i].second) / (obs[i + 1].first - obs[i].first));
    }

    printf("%.1f", fastest);
}