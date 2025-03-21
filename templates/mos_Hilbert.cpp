#ifdef ONPC
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wrange-loop-construct"
#pragma GCC diagnostic ignored "-Wsign-compare"
#endif

#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"

using namespace std;
using namespace __gnu_pbds; /*  */

bool startmemory;
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
#define print(...) 42
#define printarr(...) 42
#endif

#define MULTI  \
    int _T;    \
    cin >> _T; \
    while (_T--)

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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

/////////////////////////////////////////////////////////////////////////////////////

template <class T>
bool ckmin(T &a, const T &b) { return b < a ? a = b, 1 : 0; }

template <class T>
bool ckmax(T &a, const T &b) { return a < b ? a = b, 1 : 0; }

template <class T>
using maxheap = priority_queue<T, vector<T>>;

template <class T>
using minheap = priority_queue<T, vector<T>, greater<T>>;

template <class T>
using ordered_set = tree<T, null_type,
                         less<T>, rb_tree_tag,
                         tree_order_statistics_node_update>;

template <const int32_t MOD>
struct modint
{
    int32_t value;
    modint() = default;
    modint(int32_t value_) : value(value_) {}
    inline modint<MOD> operator+(modint<MOD> other) const
    {
        int32_t c = this->value + other.value;
        return modint<MOD>(c >= MOD ? c - MOD : c);
    }
    inline modint<MOD> operator-(modint<MOD> other) const
    {
        int32_t c = this->value - other.value;
        return modint<MOD>(c < 0 ? c + MOD : c);
    }
    inline modint<MOD> operator*(modint<MOD> other) const
    {
        int32_t c = (int64_t)this->value * other.value % MOD;
        return modint<MOD>(c < 0 ? c + MOD : c);
    }
    inline modint<MOD> &operator+=(modint<MOD> other)
    {
        this->value += other.value;
        if (this->value >= MOD)
            this->value -= MOD;
        return *this;
    }
    inline modint<MOD> &operator-=(modint<MOD> other)
    {
        this->value -= other.value;
        if (this->value < 0)
            this->value += MOD;
        return *this;
    }
    inline modint<MOD> &operator*=(modint<MOD> other)
    {
        this->value = (int64_t)this->value * other.value % MOD;
        if (this->value < 0)
            this->value += MOD;
        return *this;
    }
    inline modint<MOD> operator-() const { return modint<MOD>(this->value ? MOD - this->value : 0); }
    modint<MOD> pow(uint64_t k) const
    {
        modint<MOD> x = *this, y = 1;
        for (; k; k >>= 1)
        {
            if (k & 1)
                y *= x;
            x *= x;
        }
        return y;
    }
    modint<MOD> inv() const { return pow(MOD - 2); } // MOD must be a prime
    inline modint<MOD> operator/(modint<MOD> other) const { return *this * other.inv(); }
    inline modint<MOD> operator/=(modint<MOD> other) { return *this *= other.inv(); }
    inline bool operator==(modint<MOD> other) const { return value == other.value; }
    inline bool operator!=(modint<MOD> other) const { return value != other.value; }
    inline bool operator<(modint<MOD> other) const { return value < other.value; }
    inline bool operator>(modint<MOD> other) const { return value > other.value; }
};
template <int32_t MOD>
modint<MOD> operator*(int64_t value, modint<MOD> n) { return modint<MOD>(value) * n; }
template <int32_t MOD>
modint<MOD> operator*(int32_t value, modint<MOD> n) { return modint<MOD>(value % MOD) * n; }
template <int32_t MOD>
istream &operator>>(istream &in, modint<MOD> &n) { return in >> n.value; }
template <int32_t MOD>
ostream &operator<<(ostream &out, modint<MOD> n) { return out << n.value; }

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

template <typename T, typename T_iterable>
vector<pair<T, int>> run_length_encoding(const T_iterable &items)
{
    vector<pair<T, int>> runs;
    T previous;
    int count = 0;

    for (const T &item : items)
        if (item == previous)
        {
            count++;
        }
        else
        {
            if (count > 0)
                runs.emplace_back(previous, count);

            previous = item;
            count = 1;
        }

    if (count > 0)
        runs.emplace_back(previous, count);

    return runs;
}

struct BIT
{
    int size;
    vector<int> bit;
    BIT(int n) : size(n + 4), bit(n + 10) {}
    void update(int x, int v)
    {
        for (; x <= size; x += x & (-x))
            bit[x] += v;
    }
    int query(int b)
    {
        int result = 0;
        for (; b > 0; b -= b & (-b))
            result += bit[b];
        return result;
    }
    int query(int l, int r)
    {
        return query(r) - query(l - 1);
    }
};

int rand(int low, int high)
{
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> distribution(low, high);
    return distribution(gen);
}

int sumton(int x)
{
    double n = (-1 + sqrt(1 + 8 * x)) / 2;
    int nn = n;
    if ((n - nn) > 1e-6)
        return -1;
    else
        return nn;
}

int rangesum(int l, int r)
{
    return (r - l + 1) * (r + l) / 2;
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

const int N = 1e6 + 5;
vector<Query> qry;

string s;
int n, q, l, r, x, u, v, k;
int A[N];
int cnt[N];
void add(int idx, int &ans)
{
    if (cnt[A[idx]] % 2 == 1)
        ans--;
    cnt[A[idx]]++;
    if (cnt[A[idx]] % 2 == 1)
        ans++;
}

void rmv(int idx, int &ans)
{
    if (cnt[A[idx]] % 2 == 1)
        ans--;
    cnt[A[idx]]--;
    if (cnt[A[idx]] % 2 == 1)
        ans++;
}

void solve_the_probelm(int test_case)
{

    cin >> n >> q;

    for (int i = 1; i <= n; i++)
        cin >> A[i];

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

    for (auto q : qry)
    {

        // print(q.l, q.r, l, r);
        while (l > q.l)
        {
            // func(XOR[--l], 1, ans);
            // currans += add(a[--l]);

            add(--l, ans);
        }
        while (r < q.r)
        {
            // func(XOR[++r], 1, ans);
            // currans += add(a[++r]);
            add(++r, ans);
        }
        while (r > q.r)
        {
            // func(XOR[r--], -1, ans);
            // currans += remove(a[r--]);

            rmv(r--, ans);
        }
        while (l < q.l)
        {

            // func(XOR[l++], -1, ans);
            // currans += remove(a[l++]);
            rmv(l++, ans);
        }

        res[q.idx] = ans;
    }

    for (int i = 1; i <= q; i++)
        cout << (res[i - 1] == 0 ? "Yes" : "No") << endl;

    for (int i = 1; i <= n; i++)
        cnt[A[i]] = 0;
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