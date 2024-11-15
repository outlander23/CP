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

This will make a range with a sepcific value
NOTE: not add x to the value but replace value with the given value
100% working
one base indexing is done

segtreesum<min_t> seg;
seg.init(mxsz);
see the code for better understanding
https://codeforces.com/contest/52/submission/229397260
*/