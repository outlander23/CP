
class SegmentTree
{
private:
    std::vector<int> t;
    int n;

    void build(int v, int tl, int tr)
    {
        if (tl == tr)
        {
            t[v] = 0;
        }
        else
        {
            int tm = (tl + tr) / 2;
            build(v * 2, tl, tm);
            build(v * 2 + 1, tm + 1, tr);
            t[v] = 0;
        }
    }

    void update(int v, int tl, int tr, int l, int r, int add)
    {
        if (l > r)
            return;
        if (l == tl && r == tr)
        {
            t[v] += add;
        }
        else
        {
            int tm = (tl + tr) / 2;
            update(v * 2, tl, tm, l, std::min(r, tm), add);
            update(v * 2 + 1, tm + 1, tr, std::max(l, tm + 1), r, add);
        }
    }

    int get(int v, int tl, int tr, int pos)
    {
        if (tl == tr)
            return t[v];
        int tm = (tl + tr) / 2;
        if (pos <= tm)
            return t[v] + get(v * 2, tl, tm, pos);
        else
            return t[v] + get(v * 2 + 1, tm + 1, tr, pos);
    }

public:
    SegmentTree(int mxsz)
    {
        n = mxsz;
        t.resize(4 * n);
    }

    void build(int sz)
    {
        n = sz;
        build(1, 1, n);
    }

    void update(int l, int r, int add)
    {
        update(1, 1, n, l, r, add);
    }

    int get(int pos)
    {
        return get(1, 1, n, pos);
    }
};

// this segment tree just update the range [l, r] with add value