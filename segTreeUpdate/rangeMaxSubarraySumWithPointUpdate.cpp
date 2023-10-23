struct DynamicMaxSubarraySum
{
    struct node
    {
        int pref, suf, val, sum;
    };
    int N;
    int neutral;
    vector<node> t;
    DynamicMaxSubarraySum(int _N, int assign_value)
    {
        neutral = assign_value;
        N = _N + 1;
        t.resize(4 * N);
        for (int i = 0; i < 4 * N; i++)
            t[i] = {0, 0, 0, 0};
        build(1, 1, N);
    }
    void build(int i, int l, int r)
    {
        if (l == r)
        {
            t[i].pref = t[i].suf = t[i].val = t[i].sum = neutral;
            return;
        }
        int mid = (l + r) >> 1;
        build(2 * i, l, mid);
        build(2 * i + 1, mid + 1, r);
        t[i] = merge(t[2 * i], t[2 * i + 1]);
    }
    node merge(node a, node b)
    {
        node c;
        c.pref = max(a.pref, a.sum + b.pref);
        c.suf = max(b.suf, b.sum + a.suf);
        c.val = max({a.val, b.val, a.suf + b.pref});
        c.sum = a.sum + b.sum;
        return c;
    }

    void modif(int i, int l, int r, int pos, int val)
    {
        if (l > pos || r < pos)
            return;
        if (l == pos && r == pos)
        {
            t[i].pref = t[i].suf = t[i].val = t[i].sum = val;
            return;
        }
        int mid = (l + r) >> 1;
        modif(2 * i, l, mid, pos, val);
        modif(2 * i + 1, mid + 1, r, pos, val);
        t[i] = merge(t[2 * i], t[2 * i + 1]);
    }
    void modif(int pos, int val)
    {
        modif(1, 1, N, pos, val);
    }
    node query(int i, int l, int r, int tl, int tr)
    {
        if (l > tr || r < tl)
            return {0, 0, 0, 0};
        if (l >= tl && r <= tr)
            return t[i];
        int mid = (l + r) >> 1;
        return merge(query(2 * i, l, mid, tl, tr), query(2 * i + 1, mid + 1, r, tl, tr));
    }
    node query(int l, int r)
    {
        return query(1, 1, N, l, r); // change lower bound of l to 1
    }
    node query(int pos)
    {
        return query(1, 1, N, pos, pos);
    }
};