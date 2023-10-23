// #pragma GCC optimize "fast-math"
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")

#pragma GCC diagnostic ignored "-Wunused-variable"

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
#include "../Debug/debug.h"
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

//////////////////////////////////////-----/////////////////////////////////////////////

const int INF = 1e18;        // infinity
const int mod = 1e9 + 7;     // mod
const int base1 = 972663749; // base1
const int base2 = 998244353; // base2
const int mod1 = 1000000007; // mod1
const int mod2 = 1000000009; // mod2

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

void printVector(vector<int> &array)
{
    int sz = array.size();
    if (sz == 0)
        return;
    for (int i = 0; i < sz - 1; i++)
    {
        cout << array[i] << " ";
    }
    cout << array[sz - 1] << endl;
}

void printArray(int array[], int sz)
{
    for (int i = 0; i < sz - 1; i++)
    {
        cout << array[i] << " ";
    }
    cout << array[sz - 1] << endl;
}

//////////////////////////////////////----BITSET-function----///////////////////////////////////////////
//====================================================================================================
//====================================================================================================

struct custom_bitset
{
    vector<uint64_t> bits;
    int64_t b, n;

    custom_bitset(int64_t _b = 0)
    {
        init(_b);
    }

    void init(int64_t _b)
    {
        b = _b;
        n = (b + 63) / 64;
        bits.assign(n, 0);
    }

    void clear()
    {
        b = n = 0;
        bits.clear();
    }

    void reset()
    {
        bits.assign(n, 0);
    }

    void _clean()
    {
        // Reset all bits after `b`.
        if (b != 64 * n)
            bits.back() &= (1LLU << (b - 64 * (n - 1))) - 1;
    }

    bool get(int64_t index) const
    {
        return bits[index / 64] >> (index % 64) & 1;
    }

    void set(int64_t index, bool value)
    {
        assert(0 <= index && index < b);
        bits[index / 64] &= ~(1LLU << (index % 64));
        bits[index / 64] |= uint64_t(value) << (index % 64);
    }

    // Simulates `bs |= bs << shift;`
    void or_shift(int64_t shift)
    {
        int64_t div = shift / 64, mod = shift % 64;

        if (mod == 0)
        {
            for (int64_t i = n - 1; i >= div; i--)
                bits[i] |= bits[i - div];

            return;
        }

        for (int64_t i = n - 1; i >= div + 1; i--)
            bits[i] |= bits[i - (div + 1)] >> (64 - mod) | bits[i - div] << mod;

        if (div < n)
            bits[div] |= bits[0] << mod;

        _clean();
    }

    // Simulates `bs |= bs >> shift;`
    void or_shift_down(int64_t shift)
    {
        int64_t div = shift / 64, mod = shift % 64;

        if (mod == 0)
        {
            for (int64_t i = div; i < n; i++)
                bits[i - div] |= bits[i];

            return;
        }

        for (int64_t i = 0; i < n - (div + 1); i++)
            bits[i] |= bits[i + (div + 1)] << (64 - mod) | bits[i + div] >> mod;

        if (div < n)
            bits[n - div - 1] |= bits[n - 1] >> mod;

        _clean();
    }

    int64_t find_first() const
    {
        for (int i = 0; i < n; i++)
            if (bits[i] != 0)
                return 64 * i + __builtin_ctzll(bits[i]);

        return -1;
    }

    custom_bitset &operator&=(const custom_bitset &other)
    {
        assert(b == other.b);

        for (int i = 0; i < n; i++)
            bits[i] &= other.bits[i];

        return *this;
    }
};

//////////////////////////////////////----knapsack-function----///////////////////////////////////////////
//====================================================================================================
//====================================================================================================

/*

find max{subset_sum} <= target
complexity: O(sum * sqrt(sum) / 64)
find the max sum the can be build less then target
becarefull or use other funciton

some update was made

*/

int maxsubsetsum_knapsack(int target, vector<int> &sizes)
{

    int n = target;
    vector<int> freq(n + 1, 0);

    for (int s : sizes)
        if (1 <= s && s <= n)
            freq[s]++;

    custom_bitset knapsack(n + 1);
    knapsack.set(0, 1);

    for (int s = 1; s <= n; s++)
    {
        if (freq[s] >= 3)
        {
            int move = (freq[s] - 1) / 2;
            freq[s] -= 2 * move;

            if (2 * s <= n)
                freq[2 * s] += move;
        }

        for (int r = 0; r < freq[s]; r++)
            knapsack.or_shift(s);
    }

    for (int i = target; i >= 0; i--)
        if (knapsack.get(i))
            return i;
    return -1;
}

/*

Computes all possible subset sums from 0 to n that can be made using values from sizes.
Runs in O(n sqrt n / 64) if
the sum of sizes is bounded by n, and O(n^2 / 64) otherwise.

*/
custom_bitset possible_subsets_knapsack(int target, const vector<int> &sizes)
{
    int n = target;
    vector<int> freq(n + 1, 0);

    for (int s : sizes)
        if (1 <= s && s <= n)
            freq[s]++;

    custom_bitset knapsack(n + 1);
    knapsack.set(0, 1);

    for (int s = 1; s <= n; s++)
    {
        if (freq[s] >= 3)
        {
            int move = (freq[s] - 1) / 2;
            freq[s] -= 2 * move;

            if (2 * s <= n)
                freq[2 * s] += move;
        }

        for (int r = 0; r < freq[s]; r++)
            knapsack.or_shift(s);
    }

    return knapsack;
}

//////////////////////////////////////----main-function----///////////////////////////////////////////
//====================================================================================================
//====================================================================================================

const int N = 4e3 + 5;

// FUA
int A[N], B[N], C[N], D[N];

// FUV
int n, m, a, b, c, d, l, r, x, y, z, q, k, t;

// FUS
string s;

// MyDefinations

void solve_the_probelm(int test_case)
{

    cin >> a >> b;
    b += a;
    int sum = (b * (b - 1) / 2) - (a * (a - 1) / 2);

    vector<int> factors;
    for (int i = 2; i * i <= sum; i++)
        if (sum % i == 0)
        {
            factors.push_back(i);
            if (sum / i != i)
                factors.push_back(sum / i);
        }
    print(sum);
    int ans = 1;
    vector<int> v;

    for (int i = a; i <= b; i++)
        v.push_back(i);

    custom_bitset bs = possible_subsets_knapsack(sum, v);

    for (int x : factors)
        if (bs.get(x))
            ans = max(ans, x);

    cout << ans << endl;
}

// #define endl "\n"
// #define ONLINE_JUDGE

///////////////////////////////////------------------------///////////////////////////////////////////
//====================================================================================================
//====================================================================================================

signed main()
{

    int test_cases = 1;
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("../input.txt", "r", stdin);
    freopen("../output.txt", "w", stdout);
#endif

    cin >> test_cases; ////////////////////////////////////______test_case_____/////////////////////////

    for (int test_case = 1; test_case <= test_cases; test_case++)
        solve_the_probelm(test_case);

#ifndef ONLINE_JUDGE
    cout << "\nExecution Time : " << 1.0 * clock() / CLOCKS_PER_SEC << "s ";
#endif

    return 0;
}