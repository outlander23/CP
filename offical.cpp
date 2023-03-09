// #pragma GCC optimize "fast-math"
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC diagnostic ignored "-Wunused-variable"

#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"

using namespace std;
using namespace __gnu_pbds;

#define endl "\n"
#define EPSILON 1e-12
#define int long long
// #define ONLINE_JUDGE

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

/////////////////////////////////////----////////////////////////////////////////////////

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

//////////////////////////////////////----main-function----///////////////////////////////////////////
//====================================================================================================
//====================================================================================================

int n, k;
int a[200005];

struct DynamicMaxSubarraySum
{
    struct node
    {
        int pref, suf, val, sum;
    };
    int N;
    int neutral;
    vector<node> t;
    DynamicMaxSubarraySum(int _N, int assign_value)
    {
        neutral = assign_value;
        N = _N + 1; // add 1 to N
        t.resize(4 * N);
        for (int i = 0; i < 4 * N; i++)
            t[i] = {0, 0, 0, 0};
        build(1, 1, N); // change lower bound of build to 1
    }
    void build(int i, int l, int r)
    {
        if (l == r)
        {
            t[i].pref = t[i].suf = t[i].val = t[i].sum = neutral;
            return;
        }
        int mid = (l + r) >> 1;
        build(2 * i, l, mid);
        build(2 * i + 1, mid + 1, r);
        t[i] = merge(t[2 * i], t[2 * i + 1]);
    }
    node merge(node a, node b)
    {
        node c;
        c.pref = max(a.pref, a.sum + b.pref);
        c.suf = max(b.suf, b.sum + a.suf);
        c.val = max({a.val, b.val, a.suf + b.pref});
        c.sum = a.sum + b.sum;
        return c;
    }

    void modif(int i, int l, int r, int pos, int val)
    {
        if (l > pos || r < pos)
            return;
        if (l == pos && r == pos)
        {
            t[i].pref = t[i].suf = t[i].val = t[i].sum = val;
            return;
        }
        int mid = (l + r) >> 1;
        modif(2 * i, l, mid, pos, val);
        modif(2 * i + 1, mid + 1, r, pos, val);
        t[i] = merge(t[2 * i], t[2 * i + 1]);
    }
    void modif(int pos, int val)
    {
        modif(1, 1, N, pos, val); // change lower bound of pos to 1
    }
    node query(int i, int l, int r, int tl, int tr)
    {
        if (l > tr || r < tl)
            return {0, 0, 0, 0};
        if (l >= tl && r <= tr)
            return t[i];
        int mid = (l + r) >> 1;
        return merge(query(2 * i, l, mid, tl, tr), query(2 * i + 1, mid + 1, r, tl, tr));
    }
    node query(int l, int r)
    {
        return query(1, 1, N, l, r); // change lower bound of l to 1
    }
    node query(int pos)
    {
        return query(1, 1, N, pos, pos); // change lower bound of pos to 1
    }
};

void solve_the_probelm(int test_case)
{

    cin >> n >> k;
    DynamicMaxSubarraySum ds(n, 0);
    for (int i = 1; i <= n; i++)
        cin >> a[i];

    for (int i = 1; i < n; i++)
    {
        if (a[i] < 2 * a[i + 1])
            ds.modif(i, 1);
    }

    int ans = 0;

    for (int i = 1; i <= n - k; i++)
    {
        int sum = ds.query(i, i + k - 1).val;
        ans += (sum == k);
    }

    cout << ans << endl;
}

///////////////////////////////////------------------------///////////////////////////////////////////
//====================================================================================================
//====================================================================================================
signed main()
{
    int test_cases = 1;
    ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);

#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif

    cin >> test_cases; ////////////////////////////////////______test_case_____/////////////////////////

    for (int test_case = 1; test_case <= test_cases; test_case++)
        solve_the_probelm(test_case);

#ifndef ONLINE_JUDGE
    cout << "\nExecution Time : " << 1.0 * clock() / CLOCKS_PER_SEC << "s ";
#endif

    return 0;
}
