#ifdef ONPC
#include <sys/resource.h>
#pragma GCC diagnostic ignored "-Wunused-variable"
#pragma GCC diagnostic ignored "-Wrange-loop-construct"
#pragma GCC diagnostic ignored "-Wsign-compare"
#endif

#include "bits/stdc++.h"
#include "ext/pb_ds/assoc_container.hpp"

using namespace std;
using namespace __gnu_pbds;

bool startmemory;
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
bool isPowerOf2(int x)
{
    return x > 0 && (x & (x - 1)) == 0;
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

//////////////////////////////////////----main-function----///////////////////////////////////////////
//====================================================================================================
//====================================================================================================

const int N = 2e6 + 5;
const int K = 3e5 + 5;

// FUV
char ch;
string s, s1, s2;
int n, m, b, a, c, d, e, f, l, r, t, x, y, z, p, q, k, u, v, i, w, h;

// My Defination

// https://cses.fi/problemset/task/2413
// https://cses.fi/problemset/task/1744
// https://cses.fi/problemset/task/1653
// https://cses.fi/problemset/task/2181

const int magic = 600;
using z1 = modint<mod>;

template <typename num_t>
struct segtreemin
{
    int n;
    vector<num_t> tree, lazy;

    void init(int __mxsize)
    {
        n = __mxsize;
        tree = vector<num_t>(4 * (n + 5), INF);
        lazy = vector<num_t>(4 * (n + 5), 0);
        init(1, 1, n);
    }

    num_t init(int i, int l, int r)
    {
        if (l == r)
            return tree[i] = 0;

        int mid = (l + r) / 2;
        num_t a = init(2 * i, l, mid);
        num_t b = init(2 * i + 1, mid + 1, r);
        return tree[i] = a.op(b);
    }

    void update(int l, int r, num_t v)
    {
        if (l > r)
            return;
        update(1, 1, n, l, r, v);
    }
    void update(int pos, num_t v)
    {
        if (pos > n)
            return;
        update(1, 1, n, pos, pos, v);
    }
    num_t update(int i, int tl, int tr, int ql, int qr, num_t v)
    {
        eval_lazy(i, tl, tr);

        if (ql <= tl && tr <= qr)
        {
            lazy[i] = lazy[i].val + v.val;
            eval_lazy(i, tl, tr);
            return tree[i];
        }
        if (tl > tr || tr < ql || qr < tl)
            return tree[i];
        if (tl == tr)
            return tree[i];

        int mid = (tl + tr) / 2;
        num_t a = update(2 * i, tl, mid, ql, qr, v);
        num_t b = update(2 * i + 1, mid + 1, tr, ql, qr, v);
        return tree[i] = a.op(b);
    }

    num_t query(int l, int r)
    {
        if (l > r)
            return INF;
        return query(1, 1, n, l, r);
    }

    num_t query(int i, int tl, int tr, int ql, int qr)
    {
        eval_lazy(i, tl, tr);

        if (ql <= tl && tr <= qr)
            return tree[i];
        if (tl > tr || tr < ql || qr < tl)
            return num_t::null_v;

        int mid = (tl + tr) / 2;
        num_t a = query(2 * i, tl, mid, ql, qr);
        num_t b = query(2 * i + 1, mid + 1, tr, ql, qr);
        return a.op(b);
    }

    void eval_lazy(int i, int l, int r)
    {
        tree[i] = tree[i].lazy_op(lazy[i], (r - l + 1));
        if (l != r)
        {
            lazy[2 * i] = lazy[i].val + lazy[2 * i].val;
            lazy[2 * i + 1] = lazy[i].val + lazy[2 * i + 1].val;
        }

        lazy[i] = num_t();
    }
};

struct min_t
{
    long long val;
    static const long long null_v = INF;

    min_t() : val(0) {}
    min_t(long long v) : val(v) {}

    min_t op(min_t &other)
    {
        return min_t(min(val, other.val));
    }

    min_t lazy_op(min_t v, int size)
    {
        return min_t(val + v.val);
    }
};

/*
100% working
one base indexing is done
segtreemin<min_t> seg;
seg.init(mxsz);
see the code for better understanding
https://codeforces.com/contest/52/submission/229397260

care full about null value
*/

template <typename num_t>
struct segtreemax
{
    int n;
    vector<num_t> tree, lazy;

    void init(int __mxsize)
    {
        n = __mxsize;
        tree = vector<num_t>(4 * (n + 5), INF);
        lazy = vector<num_t>(4 * (n + 5), 0);
        init(1, 1, n);
    }

    num_t init(int i, int l, int r)
    {
        if (l == r)
            return tree[i] = 0;

        int mid = (l + r) / 2;
        num_t a = init(2 * i, l, mid);
        num_t b = init(2 * i + 1, mid + 1, r);
        return tree[i] = a.op(b);
    }

    void update(int l, int r, num_t v)
    {
        if (l > r)
            return;
        update(1, 1, n, l, r, v);
    }
    void update(int pos, num_t v)
    {
        if (pos > n)
            return;
        update(1, 1, n, pos, pos, v);
    }
    num_t update(int i, int tl, int tr, int ql, int qr, num_t v)
    {
        eval_lazy(i, tl, tr);

        if (ql <= tl && tr <= qr)
        {
            lazy[i] = lazy[i].val + v.val;
            eval_lazy(i, tl, tr);
            return tree[i];
        }
        if (tl > tr || tr < ql || qr < tl)
            return tree[i];
        if (tl == tr)
            return tree[i];

        int mid = (tl + tr) / 2;
        num_t a = update(2 * i, tl, mid, ql, qr, v);
        num_t b = update(2 * i + 1, mid + 1, tr, ql, qr, v);
        return tree[i] = a.op(b);
    }

    num_t query(int l, int r)
    {
        if (l > r)
            return 0;
        return query(1, 1, n, l, r);
    }

    num_t query(int i, int tl, int tr, int ql, int qr)
    {
        eval_lazy(i, tl, tr);

        if (ql <= tl && tr <= qr)
            return tree[i];
        if (tl > tr || tr < ql || qr < tl)
            return num_t::null_v;

        int mid = (tl + tr) / 2;
        num_t a = query(2 * i, tl, mid, ql, qr);
        num_t b = query(2 * i + 1, mid + 1, tr, ql, qr);
        return a.op(b);
    }

    void eval_lazy(int i, int l, int r)
    {
        tree[i] = tree[i].lazy_op(lazy[i], (r - l + 1));
        if (l != r)
        {
            lazy[2 * i] = lazy[i].val + lazy[2 * i].val;
            lazy[2 * i + 1] = lazy[i].val + lazy[2 * i + 1].val;
        }

        lazy[i] = num_t();
    }
};

struct max_t
{
    long long val;
    static const long long null_v = 0;

    max_t() : val(0) {}
    max_t(long long v) : val(v) {}

    max_t op(max_t &other)
    {
        return max_t(max(val, other.val));
    }

    max_t lazy_op(max_t v, int size)
    {
        return max_t(val + v.val);
    }
};

/*
100% working
one base indexing is done
segtreemax<max_t> seg;
seg.init(mxsz);
see the code for better understanding
https://codeforces.com/contest/1884/submission/229399754
https://codeforces.com/contest/893/submission/242982999

time: O(nlog(n))

care full about null value
*/

const int NEG_INF = -INF;
template <class T>
struct LazySeg
{
    int sz;
    vector<T> st, lz;

    T comb(T a, T b)
    {
        return max(a, b);
    }

    void init(int n)
    {
        sz = 1;
        while (sz < n)
            sz <<= 1;
        st.assign(2 * sz, NEG_INF);
        lz.assign(2 * sz, NEG_INF);
    }

    void pull(int i)
    {
        st[i] = comb(st[i << 1], st[i << 1 | 1]); // Update parent node with max of children
    }

    void push(int i, int l, int r)
    {
        if (lz[i] != NEG_INF)
        {
            st[i] = max(st[i], lz[i]);
            if (l != r)
            {
                lz[i << 1] = max(lz[i << 1], lz[i]);
                lz[i << 1 | 1] = max(lz[i << 1 | 1], lz[i]);
            }
            lz[i] = NEG_INF;
        }
    }

    void update(int ql, int qr, T x, int i, int l, int r)
    {
        push(i, l, r);
        if (ql > r || qr < l)
            return;

        if (ql <= l && qr >= r)
        {
            lz[i] = max(lz[i], x);
            push(i, l, r);
            return;
        }

        int m = (l + r) >> 1;
        update(ql, qr, x, i << 1, l, m);
        update(ql, qr, x, i << 1 | 1, m + 1, r);
        pull(i);
    }

    void update(int ql, int qr, T x)
    {
        update(ql, qr, x, 1, 0, sz - 1);
    }

    T query(int ql, int qr, int i, int l, int r)
    {
        push(i, l, r);
        if (ql > r || qr < l)
            return NEG_INF;

        if (ql <= l && qr >= r)
            return st[i];

        int m = (l + r) >> 1;
        return comb(query(ql, qr, i << 1, l, m), query(ql, qr, i << 1 | 1, m + 1, r)); // Query both sides
    }

    T query(int ql, int qr)
    {
        return query(ql, qr, 1, 0, sz - 1);
    }
};

void pre_process()
{
}
void solve_the_problem(int test_case)
{
    /*
       Please check the value of N :(
       Please read the problem again before coding !
    */

    cin >> n;

    LazySeg<int> dp;
    vector<int> a(n + 1);
    segtreemax<max_t> mx;
    segtreemin<min_t> mn;

    dp.init(n + 5);
    mx.init(n + 5);
    mn.init(n + 5);

    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
        mx.update(i, a[i]);
        mn.update(i, a[i]);
    }

    vector<int> res;
    for (int i = n; i >= 1; i--)
    {

        int ans = mx.query(1, i).val;

        ans = max(ans, dp.query(1, ans - 1));

        dp.update(a[i], n, ans);
        res.push_back(ans);

        // for (int j = 1; j <= n; j++)
        //     cout << dp.query(j, j) << " \n"[j == n];
    }

    reverse(res.begin(), res.end());
    printVector(res);
}

bool endmemory;
signed main()
{

#ifdef ONPC
    const rlim_t stackSize = 1024 * 1024 * 1024; // 1 GB
    struct rlimit rl;
    rl.rlim_cur = stackSize;
    rl.rlim_max = stackSize;
#endif

    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cout << fixed << setprecision(14);

#ifdef ONPC

    char name[] = "input.txt";

    freopen(name, "r", stdin);
    freopen("output.txt", "w", stdout);

#endif

    pre_process();

    cin >> test_cases;
    for (int test_case = 1; test_case <= test_cases; test_case++)
    {
        // cout << "Case " << test_case << ": ";
        solve_the_problem(test_case);
#ifdef ONPC
        // cout << "================================================================" << endln;
#endif
    }

#ifdef ONPC
    if (setrlimit(RLIMIT_STACK, &rl) != 0)
        std::cerr << "Error setting stack size: " << strerror(errno) << std::endl;
    cout << "Stack size: " << stackSize / 1024 / 1024 / 1024 << "GB \n";
    cout << "Execution Time : " << 1.0 * clock() / CLOCKS_PER_SEC << "s\n";
    cout << "Execution Memory : " << (&endmemory - &startmemory) / (1024 * 1024) << "MB\n";

#endif

    return 0;
}