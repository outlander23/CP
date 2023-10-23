template <typename T, typename L = T>
struct SegmentTreeLazy
{
    int n;
    vector<T> tree;
    vector<L> lazy;

    // ----------

    template <typename VAL_T>
    T get_tree_val(VAL_T &val)
    {
        return val;
    }

    T merge(T a, T b)
    {
        return max(a, b);
    }

    T lazy_apply(T val_curr, L val_lazy, int l, int r)
    {
        return (val_curr + val_lazy);
    }

    L lazy_pull(L val_curr, L val_new)
    {
        return (val_curr + val_new);
    }

    L DEF_LAZY = 0;

    // ----------

    SegmentTreeLazy(int n = 0) : n(n)
    {
        tree.resize(n << 2);
        lazy.resize(n << 2);
        fill(lazy.begin(), lazy.end(), DEF_LAZY);
    }

    SegmentTreeLazy(int n, T val) : SegmentTreeLazy(n)
    {
        fill(tree.begin(), tree.end(), val);
    }

    template <typename VAL_T>
    SegmentTreeLazy(vector<VAL_T> &data) : SegmentTreeLazy((int)data.size())
    {
        __build(0, 0, n - 1, data);
    }

    template <typename VAL_T>
    void __build(int ti, int left, int right, vector<VAL_T> &data)
    {
        if (left == right)
        {
            tree[ti] = get_tree_val(data[left]);
            return;
        }

        int tl, tr, tm;
        tl = (ti << 1) + 1;
        tr = (ti << 1) + 2;
        tm = (left + right) >> 1;

        __build(tl, left, tm, data);
        __build(tr, tm + 1, right, data);
        tree[ti] = merge(tree[tl], tree[tr]);
    }

    void __push(int ti, int left, int right)
    {
        if (lazy[ti] == DEF_LAZY)
            return;
        tree[ti] = lazy_apply(tree[ti], lazy[ti], left, right);

        int tl, tr;
        tl = (ti << 1) + 1;
        tr = (ti << 1) + 2;

        if (left != right)
        {
            lazy[tl] = lazy_pull(lazy[tl], lazy[ti]);
            lazy[tr] = lazy_pull(lazy[tr], lazy[ti]);
        }

        lazy[ti] = DEF_LAZY;
    }

    void __update(int ti, int left, int right, int l, int r, L val)
    {
        __push(ti, left, right);
        if ((l > right) || (r < left))
            return;
        if ((l <= left) && (right <= r))
        {
            lazy[ti] = lazy_pull(lazy[ti], val);
            __push(ti, left, right);
            return;
        }

        int tl, tr, tm;
        tl = (ti << 1) + 1;
        tr = (ti << 1) + 2;
        tm = (left + right) >> 1;

        __update(tl, left, tm, l, r, val);
        __update(tr, tm + 1, right, l, r, val);
        tree[ti] = merge(tree[tl], tree[tr]);
    }

    T __query(int ti, int left, int right, int l, int r)
    {
        __push(ti, left, right);
        if ((l <= left) && (right <= r))
            return tree[ti];

        int tl, tr, tm;
        tl = (ti << 1) + 1;
        tr = (ti << 1) + 2;
        tm = (left + right) >> 1;

        if (l > tm)
            return __query(tr, tm + 1, right, l, r);
        if (r <= tm)
            return __query(tl, left, tm, l, r);
        return merge(
            __query(tl, left, tm, l, r),
            __query(tr, tm + 1, right, l, r));
    }

    void update(int l, int r, L val) { __update(0, 0, n - 1, l, r, val); }
    T query(int l, int r) { return __query(0, 0, n - 1, l, r); }
};