
template <class T>
struct LazySeg
{
    int sz;
    vector<T> st, lz;
    const int NEG_INF = -INF;

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

/*
// make l,r = max value
// update [l,r] = max(l...r,curr)
// query [l,r] = mx

*/
