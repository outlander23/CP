#ifdef ONPC
#pragma GCC diagnostic ignored "-Wunused-variable"
#endif

#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"

using namespace std;
using namespace __gnu_pbds;

#define endln "\n"
#define EPSILON 1e-12
#define int long long
#define front_zero(n) __builtin_clzll(n)
#define back_zero(n) __builtin_ctzll(n)
#define total_one(n) __builtin_popcountll(n)

#ifdef ONPC
#include "Debug/debug.h"
#else
#define print(...) 42
#endif

#define MULTI  \
    int _T;    \
    cin >> _T; \
    while (_T--)

typedef tree<int, null_type,
             less<int>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set;

typedef tree<pair<int, int>, null_type,
             less<pair<int, int>>, rb_tree_tag,
             tree_order_statistics_node_update>
    ordered_set_pair;

int test_cases = 1;
const int INF = 1e18;    // infinity
const int mod = 1e9 + 7; // mod

const int base1 = 972663749; // base1
const int base2 = 998244353; // base2

const int mod1 = 1e9 + 7; // mod1
const int mod2 = 1e9 + 9; // mod2

const double pi = 4 * atan(1);

vector<int> dx = {-1, +1, +0, +0, +1, -1, +1, -1};
vector<int> dy = {+0, +0, +1, -1, +1, -1, -1, +1};

/////////////////////////////////////////////////////////////////////////////////////

void setIO(string s)
{
    freopen((s + ".in").c_str(), "r", stdin);
    freopen((s + ".out").c_str(), "w", stdout);
}

int modpower(int x, int n, int m)
{
    if (n == 0)
        return 1 % m;
    int u = modpower(x, n / 2, m);
    u = (u * u) % m;
    if (n % 2 == 1)
        u = (u * x) % m;
    return u;
}
int power(int x, int n)
{
    if (n == 0)
        return 1;
    int u = power(x, n / 2);
    u = (u * u);
    if (n % 2 == 1)
        u = (u * x);
    return u;
}
int modinverse(int i, int MOD)
{
    if (i == 1)
        return 1;
    return (MOD - ((MOD / i) * modinverse(MOD % i, MOD)) % MOD + MOD) % MOD;
}
int lcm(int x1, int x2)
{
    return ((x1 * x2) / __gcd(x1, x2));
}
int bitCount(unsigned int u)
{
    unsigned int uCount;
    uCount = u - ((u >> 1) & 033333333333) - ((u >> 2) & 011111111111);
    return ((uCount + (uCount >> 3)) & 030707070707) % 63;
}
void printVector(vector<int> &array, int startIndex = 0)
{
    int sz = array.size();
    if (sz == 0)
        return;
    sz += startIndex;
    for (int i = startIndex; i < sz - 1; i++)
    {
        cout << array[i] << " ";
    }
    cout << array[sz - 1] << endl;
}
void printArray(int array[], int sz, int startIndex = 0)
{
    sz += startIndex;
    for (int i = startIndex; i < sz - 1; i++)
    {
        cout << array[i] << " ";
    }
    cout << array[sz - 1] << endl;
}

//////////////////////////////////////----main-function----///////////////////////////////////////////
//====================================================================================================
//====================================================================================================

const int N = 2e5 + 5;

// FUA
// int A[N], B[N], C[N], D[N];

// FUV
int n, m, a, b, c, d, l, r, x, y, z, p, q, k, t, u, v, w;

// FUS
string s;

// MyDefinations

vector<int> prefix_function(string const &s)
{
    int n = (int)s.length();
    vector<int> pi(n);
    for (int i = 1; i < n; i++)
    {
        int j = pi[i - 1];
        while (j > 0 && s[i] != s[j])
            j = pi[j - 1];
        if (s[i] == s[j])
            j++;
        pi[i] = j;
    }
    return pi;
}

vector<int> z_function(string const &s)
{
    int n = s.size();
    vector<int> z(n);
    int l = 0, r = 0;
    for (int i = 1; i < n; i++)
    {
        if (i < r)
        {
            z[i] = min(r - i, z[i - l]);
        }
        while (i + z[i] < n && s[z[i]] == s[i + z[i]])
        {
            z[i]++;
        }
        if (i + z[i] > r)
        {
            l = i;
            r = i + z[i];
        }
    }
    return z;
}

class PolynomialHashing
{
    int base, mod;
    vector<int> power, hash;

public:
    PolynomialHashing(int base = 181, int mod = 1e9 + 7) : base(base), mod(mod)
    {
        power.push_back(1);
        hash.push_back(0);
    }
    void add_string(string &s)
    {
        for (auto c : s)
            add(c);
    }
    void add(int c)
    {
        hash.push_back(((hash.back() * base) % mod + c) % mod);
        power.push_back((power.back() * base) % mod);
    }
    int hashvalue()
    {
        return hash.back();
    }
    int changeInPos(int pos, int c)
    {
        int old = hash.back();
        int posChar = (get(pos, pos) * power[power.size() - pos - 1]) % mod;
        old -= posChar;
        if (old < 0)
            old += mod;
        old = (old + (c * power[power.size() - pos - 1]) % mod) % mod;
        return old;
    }
    int get(int l, int r)
    {
        return (hash[r] - hash[l - 1] * power[r - l + 1] % mod + mod) % mod;
    }
    int getpower(int n)
    {
        return power[n];
    }
    void clear()
    {
        power.clear();
        hash.clear();
        power.push_back(1);
        hash.push_back(0);
    }
};
// PolynomialHashing h1(base1, mod1), h2(base2, mod2);

// bool is_possilbe(int sz)
// {
//     return (h1.get(1, 1 + sz - 1) == h1.get(n - sz + 1, n)) and h2.get(1, 1 + sz - 1) == h2.get(n - sz + 1, n);
// }

void solve_the_problem(int test_case)
{
    cin >> s;
    n = s.size();
    vector<int> z = z_function(s);
    vector<int> pi = prefix_function(s);

    // h1.add_string(s);
    // h2.add_string(s);

    print(z);
    print(pi);

    int ans = 1;
    for (int i = n - 1; i >= 0; i--)
        if (i + z[i] == n)
            ans++;

    vector<int> csum(n + 1, 0);
    for (int i = 0; i < n; i++)
        csum[z[i]]++;
    print(csum);

    for (int i = s.size() - 1; i >= 1; i--)
        csum[i] += csum[i + 1];
    print(csum);

    print(z);

    cout << ans << endl;
    int index = 1;
    for (int i = n - 1; i >= 0; i--, index++)
        if (i + z[i] == n)
            cout << index << " " << csum[index] + 1 << endl;
    cout << n << " " << 1 << endl;
}

signed main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

#ifdef ONPC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    // cin >> test_cases;
    for (int test_case = 1; test_case <= test_cases; test_case++)
    {
        // cout << "Case " << test_case << ": ";
        solve_the_problem(test_case);
#ifdef ONPC
        cout << "================================================================" << endln;
#endif
    }
#ifdef ONPC
    cout << "Execution Time : " << 1.0 * clock() / CLOCKS_PER_SEC << "s";
#endif

    return 0;
}