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

const int N = 400005;

// FUA
// int A[N], B[N], C[N], D[N];

// FUV
int n, m, a, b, c, d, l, r, x, y, z, p, q, k, t, u, v, w;

// FUS
string s;

// MyDefinations
struct my_data
{
    int val;

    my_data(int _val = 0) : val(_val) {}

    my_data operator+(const my_data &other) const
    {
        return my_data(val + other.val);
    }

    operator int() const
    {
        return val;
    }
};

template <typename num_t>
struct segtree
{
    vector<num_t> s;
    vector<num_t> a;
    vector<int> lazy;
    int n;

    void init(int _n)
    {
        n = _n;
        a.assign(n + 5, num_t(0));
        s.resize(4 * (n + 5), num_t(0));
        lazy.assign(4 * (n + 5), -1);
        build(1, n);
    }

    void build(int l, int r, int u = 1)
    {
        if (l == r)
            return;
        int m = l + r >> 1;
        build(l, m, u * 2);
        build(m + 1, r, u * 2 + 1);
        s[u] = s[u * 2] + s[u * 2 + 1];
    }

    void push(int u, int d, int l, int r)
    {
        s[u] = num_t(d * (r - l + 1));
        lazy[u] = d;
    }

    void push(int u, int l, int r)
    {
        if (~lazy[u])
        {
            int m = l + r >> 1;
            push(u * 2, lazy[u], l, m);
            push(u * 2 + 1, lazy[u], m + 1, r);
            lazy[u] = -1;
        }
    }

    void update(int l, int r, int d, int ul, int ur, int u)
    {
        if (ul >= l && ur <= r)
        {
            push(u, d, ul, ur);
            return;
        }
        push(u, ul, ur);
        int m = ul + ur >> 1;
        if (l <= m)
            update(l, r, d, ul, m, u * 2);
        if (r > m)
            update(l, r, d, m + 1, ur, u * 2 + 1);
        s[u] = s[u * 2] + s[u * 2 + 1];
    }

    void update(int l, int r, int d)
    {
        update(l, r, d, 1, n, 1);
    }

    num_t query(int l, int r, int ul, int ur, int u)
    {
        if (ul >= l && ur <= r)
        {
            return s[u];
        }
        push(u, ul, ur);
        int m = ul + ur >> 1;
        if (r <= m)
            return query(l, r, ul, m, u * 2);
        if (l > m)
            return query(l, r, m + 1, ur, u * 2 + 1);
        return query(l, r, ul, m, u * 2) + query(l, r, m + 1, ur, u * 2 + 1);
    }

    num_t query(int l, int r)
    {
        return query(l, r, 1, n, 1);
    }
};

/*
100% working
one base indexing is done
segtreesum<min_t> seg;
seg.init(mxsz);
see the code for better understanding
https://codeforces.com/contest/240/submission/229534043
*/

void solve_the_problem(int test_case)
{
    cin >> n >> m;
    segtree<my_data> seg;
    seg.init(n);

    vector<int> a(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> a[i], seg.update(i, i, a[i]);

    cout << (seg.query(1, n)) << endl;
    while (m--)
    {
        cin >> l >> r >> x;

        for (int i = l; i <= r; i++)
            a[i] = x;

        print(a);
        seg.update(l, r, x);
        cout << (seg.query(1, n).val) << endl;
    }
}

signed main()
{

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    // #ifdef ONPC
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    // #endif

    // cin >> test_cases;
    for (int test_case = 1; test_case <= test_cases; test_case++)
    {
        // cout << "Case #" << test_case << ": ";
        solve_the_problem(test_case);
#ifdef ONPC
        // cout << "================================================================" << endln;
#endif
    }
#ifdef ONPC
    // cout << "Execution Time : " << 1.0 * clock() / CLOCKS_PER_SEC << "s";
#endif

    return 0;
}