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

//////////////////////////////////////----main-function----///////////////////////////////////////////
//====================================================================================================
//====================================================================================================

void solve_the_probelm(int test_case)
{
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