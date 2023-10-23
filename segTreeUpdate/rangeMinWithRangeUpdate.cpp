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
one base indexing is done
segtreemin<min_t> seg;
seg.init(mxsz);
see the code for better understanding
https://codeforces.com/contest/52/submission/229397260
*/