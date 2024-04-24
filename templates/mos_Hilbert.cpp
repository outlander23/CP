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

#ifdef ONPC
#include "../Debug/debug.h"
#else
#define print(...) 42
#endif
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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
        return 0;
    int hpow = 1 << (pow - 1);
    int seg = (x < hpow) ? ((y < hpow) ? 0 : 3) : ((y < hpow) ? 1 : 2);
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
    int64_t l, r, idx, ord;
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

const int N = 2e5 + 5;
vector<Query> qry;

int n, q, l, r, x, u, v, k;
string s;

// void func(int val, int operation, int &ans)
// {
//     if (operation == 1)
//     {
//     }
//     else
//     {
//     }
// }

void solve_the_probelm(int test_case)
{
    cin >> n >> q;

    vector<int> a(n + 1), csum(n + 1);

    for (int i = 1; i <= n; i++)
        cin >> a[i], csum[i] = csum[i - 1] + a[i];

    // vector<int> temp = a;

    // sort(temp.begin(), temp.end());
    // int index = 0;
    // a[temp[0].second] = ++index;

    // for (int i = 1; i < temp.size(); i++)
    // {
    //     if (temp[i].first == temp[i - 1].first)
    //     {
    //         a[temp[i].second] = index;
    //     }
    //     else
    //     {
    //         a[temp[i].second] = ++index;
    //     }
    // }

    // print(a);

    vector<pair<int, int>> v;

    for (int i = 1; i <= n; i++)
        v.push_back({a[i], i});

    sort(v.begin(), v.end());

    // print(v);

    int index = 0;
    a[v[0].second] = ++index;
    for (int i = 1; i < v.size(); i++)
    {
        if (v[i].first == v[i - 1].first)
        {
            a[v[i].second] = index;
        }
        else
        {
            a[v[i].second] = ++index;
        }
    }

    vector<int> tmp(index + 10);

    // don't change
    // -------------------------------
    qry.resize(q);
    vector<int> res(q);
    for (int i = 0; i < q; i++)
        cin >> l >> r, qry[i].l = l, qry[i].r = r, qry[i].idx = i, qry[i].calcOrder();
    sort(qry.begin(), qry.end());
    int ans = 0;
    int l = 1, r = 0;
    // -------------------------------

    // maxheap<pair<int, int>> mx;

    // for (auto q : qry)
    // {

    //     while (l > q.l)
    //     { // currans += add(a[--l]);
    //         l--;

    //         cnt[a[l]]++;
    //     }
    //     while (r < q.r)
    //     { // currans += add(a[++r]);
    //         r++;
    //         cnt[a[r]]++;
    //     }
    //     while (r > q.r)
    //     { // currans += remove(a[r--]);

    //         cnt[a[r]]--;
    //         r--;
    //     }
    //     while (l < q.l)
    //     { // currans += remove(a[l++]);

    //         cnt[a[l]]--;
    //         l++;
    //     }

    //     int len = q.r - q.l + 1;
    //     int mx = 0;

    //     // if (len / 2 < it.first)
    //     //     res[q.idx] = 0;
    //     // else
    //     //     res[q.idx] = 1;
    // }

    for (auto q : qry)
    {

        // print(q.l, q.r, l, r);
        while (l > q.l)
        {
            // func(XOR[--l], 1, ans);
            // currans += add(a[--l]);
            l--;
            // add(A[l]);
            tmp[a[l]]++;
        }
        while (r < q.r)
        {
            // func(XOR[++r], 1, ans);
            // currans += add(a[++r]);
            r++;
            // add(A[r]);
            tmp[a[r]]++;
        }
        while (r > q.r)
        {

            // func(XOR[r--], -1, ans);
            // currans += remove(a[r--]);

            // del(A[r]);
            tmp[a[r]]--;
            r--;
        }
        while (l < q.l)
        {

            // func(XOR[l++], -1, ans);
            // currans += remove(a[l++]);

            // del(A[l]);
            tmp[a[l]]--;
            l++;
        }
        if (q.r - q.l + 1 == 1)
        {
            res[q.idx] = 0;
            continue;
        }
        /// some change
        int ans = 1;
        for (int i = 1; i <= 80; ++i)
        {
            int aux = (rng() % (q.r - q.l + 1)) + q.l;

            if (tmp[a[aux]] > (q.r - q.l + 1) / 2 and a[aux] == 1)
                ans = 0;
        }
        res[q.idx] = ans;

        // printVector(res);
    }
    for (int i = 1; i <= q; i++)
        cout << (res[i - 1] ? "Yes" : "No") << endl;
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

    cin >> test_cases; ////////////////////////////////////______test_case_____/////////////////////////

    for (int test_case = 1; test_case <= test_cases; test_case++)
        solve_the_probelm(test_case);

#ifndef ONLINE_JUDGE
    cout << "\nExecution Time : " << 1.0 * clock() / CLOCKS_PER_SEC << "s ";
#endif

    return 0;
}