template <class T>
struct LazySeg
{
    int sz;
    vector<T> st, lz;
    const int INF = 1e18;
    T comb(T a, T b)
    {
        return min(a, b);
    }

    void init(int n)
    {
        sz = 1;
        while (sz < n)
            sz <<= 1;
        st.assign(2 * sz, INF);
        lz.assign(2 * sz, INF);
    }

    void pull(int i)
    {
        st[i] = comb(st[i << 1], st[i << 1 | 1]);
    }

    void push(int i, int l, int r)
    {
        if (lz[i] != INF)
        {
            st[i] = min(st[i], lz[i]);
            if (l != r)
            {
                lz[i << 1] = min(lz[i << 1], lz[i]);
                lz[i << 1 | 1] = min(lz[i << 1 | 1], lz[i]);
            }
            lz[i] = INF;
        }
    }

    void update(int ql, int qr, T x, int i, int l, int r)
    {
        push(i, l, r);
        if (ql > r || qr < l)
            return;

        if (ql <= l && qr >= r)
        {
            lz[i] = min(lz[i], x);
            push(i, l, r);
            return;
        }

        int m = (l + r) >> 1;
        update(ql, qr, x, i << 1, l, m);         // Update left child
        update(ql, qr, x, i << 1 | 1, m + 1, r); // Update right child
        pull(i);                                 // Pull the updated values from children
    }

    void update(int ql, int qr, T x)
    {
        update(ql, qr, x, 1, 0, sz - 1);
    }

    T query(int ql, int qr, int i, int l, int r)
    {
        push(i, l, r);
        if (ql > r || qr < l)
            return INF;

        if (ql <= l && qr >= r)
            return st[i];

        int m = (l + r) >> 1;
        return comb(query(ql, qr, i << 1, l, m), query(ql, qr, i << 1 | 1, m + 1, r));
    }

    T query(int ql, int qr)
    {
        return query(ql, qr, 1, 0, sz - 1);
    }
};

/*

README
update [l,r] make the rage minium value
query [l,r] return minimum of that range

*/