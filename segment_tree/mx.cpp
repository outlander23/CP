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
        st.assign(2 * sz, 0), lz.assign(2 * sz, 0);
    }
    void pull(int i)
    {
        st[i] = comb(st[i << 1], st[i << 1 | 1]);
    }
    void push(int i, int l, int r)
    {
        st[i] += lz[i];
        if (l != r)
            lz[i << 1] += lz[i], lz[i << 1 | 1] += lz[i];
        lz[i] = 0;
    }
    void update(int ql, int qr, T x, int i, int l, int r)
    {
        push(i, l, r);
        if (ql > r || qr < l)
            return;
        if (ql <= l && qr >= r)
        {
            lz[i] += x;
            return void(push(i, l, r));
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
            return -INF;
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

LazySeg<long long> st;

/*
100% working
zero base indexing is done

[l,r]+=add
[l,r] = mx

time: O(nlog(n))

care full about null value
here null is -INF
*/