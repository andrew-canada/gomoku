#include <iostream>

#define pb push_back
#define loop(n) for (int k = 0; k < n; k++)
#define buffer_sz (7 << 20)
int _index = 0;
char _c, _buffer[buffer_sz];
#define fs(x) for (x = _buffer[_index++] - 48; 47 < (_c = _buffer[_index++]); x = x * 10 + _c - 48)

using namespace std;

int burgers[1000005], last[500005];
double memo[1000005];

int main()
{
    fread(_buffer, 1, buffer_sz, stdin);
    int N;
    fs(N);
    loop(N)
    {
        fs(burgers[k]);
        last[burgers[k]] = k;
    }
    int coach = burgers[0], josh = burgers[N - 1];
    if (coach == josh)
    {
        cout << 1.0;
        return 0;
    }
    double total = 1.0;
    memo[coach] = 1.0;
    int bur = 0;
    for (int i = N - 1; i >= 1; i--)
    {
        bur = burgers[i];
        if (last[bur] == i && bur != coach && bur != josh)
            memo[bur] = total / (N - i);
        total += memo[bur];
    }
    cout << total / N << endl;
    return 0;
}