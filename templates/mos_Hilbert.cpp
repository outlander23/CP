// #pragma GCC optimize "fast-math"
// #pragma GCC optimize("O3,unroll-loops")
// #pragma GCC target("avx2,bmi,bmi2,lzcnt,popcnt")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,avx2,fma")
#pragma GCC diagnostic ignored "-Wunused-variable"

#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"

using namespace std;
using namespace __gnu_pbds;

#define EPSILON 1e-12
#define int long long

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

//////////////////////////////////////----Mo's-Algorithm----///////////////////////////////////////////
//====================================================================================================
//====================================================================================================

inline int64_t gilbertOrder(int x, int y, int pow, int rotate)
{
    if (pow == 0)
    {
        return 0;
    }
    int hpow = 1 << (pow - 1);
    int seg = (x < hpow) ? (
                               (y < hpow) ? 0 : 3)
                         : (
                               (y < hpow) ? 1 : 2);
    seg = (seg + rotate) & 3;
    const int rotateDelta[4] = {3, 0, 0, 1};
    int nx = x & (x ^ hpow), ny = y & (y ^ hpow);
    int nrot = (rotate + rotateDelta[seg]) & 3;
    int64_t subSquareSize = int64_t(1) << (2 * pow - 2);
    int64_t ans = seg * subSquareSize;
    int64_t add = gilbertOrder(nx, ny, pow - 1, nrot);
    ans += (seg == 1 || seg == 2) ? add : (subSquareSize - add - 1);
    return ans;
}

struct Query
{
    int l, r, idx;
    int64_t ord;

    inline void calcOrder()
    {
        ord = gilbertOrder(l, r, 21, 0);
    }
};

inline bool operator<(const Query &a, const Query &b)
{
    return a.ord < b.ord;
}

//////////////////////////////////////----main-function----///////////////////////////////////////////
//====================================================================================================
//====================================================================================================

const int N = 1e6 + 5;
int n, q, l, r, u, v, k;
vector<Query> qry;

int A[N], CNT[N];

void func(int val, int operation, int &ans)
{
    if (operation == 1)
    {
    }
    else
    {
    }
}

void solve_the_probelm(int test_case)
{
    cin >> n >> q >> k;
    for (int i = 1; i <= n; i++)
        cin >> A[i];

    XOR[1] = A[1];
    for (int i = 2; i <= n; i++)
        XOR[i] = XOR[i - 1] ^ A[i];

    // don't change
    qry.resize(q);
    vector<int> res(q);
    for (int i = 0; i < q; i++)
        cin >> l >> r, qry[i].l = l, qry[i].r = r, qry[i].idx = i, qry[i].calcOrder();
    sort(qry.begin(), qry.end());

    int ans = 0;

    int l = 1, r = 1;

    for (auto q : qry)
    {
        while (l > q.l)
        {
            func(XOR[--l], 1, ans);
            // currans += add(a[--l]);
        }
        while (r < q.r)
        {
            func(XOR[++r], 1, ans);
            // currans += add(a[++r]);
        }
        while (r > q.r)
        {
            func(XOR[r--], -1, ans);
            // currans += remove(a[r--]);
        }
        while (l < q.l)
        {
            func(XOR[l++], -1, ans);
            // currans += remove(a[l++]);
        }

        res[q.idx] = ans;
    }

    printVector(res);
}

#define endl "\n"
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

    // cin >> test_cases; ////////////////////////////////////______test_case_____/////////////////////////

    for (int test_case = 1; test_case <= test_cases; test_case++)
        solve_the_probelm(test_case);

#ifndef ONLINE_JUDGE
    cout << "\nExecution Time : " << 1.0 * clock() / CLOCKS_PER_SEC << "s ";
#endif

    return 0;
}