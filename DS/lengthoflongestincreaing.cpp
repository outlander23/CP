#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> pii;

#define pb push_back
#define mp make_pair
#define mt make_tuple
#define eb emplace_back
#define em push
#define X first
#define Y second
#define all(v) v.begin(), v.end()
#define uniq(v)   \
    sort(all(v)); \
    v.erase(unique(all(v)), v.end())
#define _                        \
    ios::sync_with_stdio(false); \
    cin.tie(0);

#define trace1(x) cerr << #x << ": " << x << endl;
#define trace2(x, y) cerr << #x << ": " << x << " | " << #y << ": " << y << endl;
#define trace3(x, y, z) cerr << #x << ": " << x << " | " << #y << ": " << y << " | " << #z << ": " << z << endl;

#define endl '\n'
#define MAX 100010
#define MOD 1000000007
namespace segmentTree
{
    LL input[MAX];
    struct data
    {
        LL ans, Lis, Ris, L, R, Lm, Rm;
    };
    data tree[3 * MAX];
    data combine_data(data left, data right)
    {
        data res;
        res.ans = max(left.ans, right.ans);
        if (left.Rm < right.Lm)
            res.ans = max(res.ans, left.Ris + right.Lis);

        res.L = left.L;
        res.R = right.R;
        res.Lm = left.Lm;
        res.Rm = right.Rm;
        res.Lis = left.Lis;
        res.Ris = right.Ris;

        if (left.Lis == (left.R - left.L + 1) && left.Rm < right.Lm)
            res.Lis += right.Lis;
        if (right.Ris == (right.R - right.L + 1) && left.Rm < right.Lm)
            res.Ris += left.Ris;

        return res;
    }
    data make_data(int val, int b)
    {
        data res;
        res.ans = res.Lis = res.Ris = 1;
        res.Lm = res.Rm = val;
        res.L = res.R = b;
        return res;
    }
    void init_tree(int node, int b, int e)
    {
        if (b == e) // leaf node
        {
            tree[node] = make_data(input[b], b);
            return;
        }
        int mid = (b + e) / 2;
        init_tree(2 * node, b, mid);
        init_tree(2 * node + 1, mid + 1, e);
        tree[node] = combine_data(tree[2 * node], tree[2 * node + 1]);
    }
    void update(int node, int b, int e, int index, int newval)
    {
        if (b == e)
        {
            tree[node].Lm += newval;
            tree[node].Rm += newval;
            return;
        }

        int mid = (b + e) / 2;

        if (index <= mid)
            update(2 * node, b, mid, index, newval);
        else
            update(2 * node + 1, mid + 1, e, index, newval);

        tree[node] = combine_data(tree[2 * node], tree[2 * node + 1]);
    }
    data query(int node, int b, int e, int i, int j)
    {
        if (b >= i && e <= j) // in range
            return tree[node];

        int mid = (b + e) / 2;
        if (j <= mid)
            return query(2 * node, b, mid, i, j);
        else if (i > mid)
            return query(2 * node + 1, mid + 1, e, i, j);

        data p1 = query(2 * node, b, mid, i, j);
        data p2 = query(2 * node + 1, mid + 1, e, i, j);

        return combine_data(p1, p2);
    }

}
using namespace segmentTree;
int main()
{
    _ int t, n, q, a, b, type;
    cin >> t;
    while (t--)
    {
        cin >> n >> q;
        for (int i = 1; i <= n; i++)
            cin >> input[i];

        init_tree(1, 1, n);

        while (q--)
        {
            cin >> type >> a >> b;
            if (type == 0)
            {
                data ret = query(1, 1, n, a, b);
                cout << ret.ans << endl;
            }
            else
                update(1, 1, n, a, b);
        }
    }
    return 0;
}