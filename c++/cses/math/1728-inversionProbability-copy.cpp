#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 2e18

const int mxN = 100;

int r[mxN + 1];

double gaussian_round(double num, int decimals)
{
    double factor = std::pow(10.0, decimals);
    double n2 = num * (factor * 10);
    n2 = floor(n2);
    n2 /= 10;
    num *= factor;
    if (std::floor(num) + 0.5 == n2 && static_cast<int>(num) % 2 == 0)
    {
        num = std::floor(num);
    }
    else
    {
        num = std::round(num);
    }
    return num / factor;
}

int main()
{
    int n;
    cin >> n;
    double ans = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> r[i];
        for (int j = 0; j < i; j++)
        {
            int c = min(r[i], r[j]) * (min(r[i], r[j]) - 1) / 2;
            if (r[j] > r[i])
            {
                c += (r[j] - r[i]) * r[i];
            }
            ans += (double)c / (r[i] * r[j]);
        }
    }
    cout << fixed << setprecision(6) << gaussian_round(ans, 7);
}