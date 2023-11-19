#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;
#define fs first
#define sn second
#define pb push_back
#define ALL(v) begin(v), end(v)
#define SZ(v) ((int)(v).size())
#define ms(a, x) memset(a, x, sizeof(a))
const int INF = 0x3f3f3f3f;
#define FR(i, n) for (int i = 0; i < (n); i++)
#define FOR(i, a, b) for (int i = (a); i < (b); i++)
#define FORR(i, a, b) for (int i = (a); i >= (b); i--)
#define dbg(x)                          \
    {                                   \
        cerr << #x << ' ' << x << endl; \
    }
#define dbgArr(arr, n)                \
    {                                 \
        cerr << #arr;                 \
        FR(_i, n)                     \
            cerr << ' ' << (arr)[_i]; \
        cerr << endl;                 \
    }

const int MN = 1e6 + 5;
const int MOD = 1e6 + 3;

namespace Mod
{
    int fact[MN];

    void initFact()
    {
        fact[0] = 1;
        FOR(i, 1, MN)
        fact[i] = (ll)fact[i - 1] * i % MOD;
    }

    ll fpow(ll a, ll b)
    {
        ll res = 1;
        for (a %= MOD; b; b >>= 1)
        {
            if (b & 1)
                res = res * a % MOD;
            a = a * a % MOD;
        }
        return res;
    }

    ll modInv(ll a)
    {
        return fpow(a, MOD - 2);
    }

    ll choose(int n, int k)
    {
        assert(k <= n && n >= 0);
        return (ll)fact[n] * modInv(fact[k]) % MOD * modInv(fact[n - k]) % MOD;
    }
}
using namespace Mod;

int n, k;
int arr[MN];
int rrr[MN];

int main()
{
    initFact();
    cin.sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    FR(i, n - k + 1)
        cin >> arr[i];
    FR(i, n - k)
    {
        int dif = arr[i] - arr[i + 1];
        if (dif == 1)
        {
            if (!rrr[i % k])
                rrr[i % k] = 1;
        }
        else if (dif == -1)
        {
            if (!rrr[i % k])
                rrr[i % k] = -1;
        }
        else
            assert(dif == 0);
    }

    int req = arr[0];
    int av = 0;
    FR(i, k)
    {
        req -= rrr[i] == 1;
        av += rrr[i] == 0;
    }

    cout << choose(av, req) << '\n';
}