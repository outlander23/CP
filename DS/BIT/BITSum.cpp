// ONE BASE INDEXING
struct BIT
{
    int size;
    vector<int> bit;
    BIT(int n) : size(n + 4), bit(n + 5) {}
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

    // return the index of the first element >= k
    int kth(int k)
    {
        int l = 0, h = size;
        while (l < h)
        {
            int mid = (l + h) / 2;
            if (query(mid) >= k)
                h = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};

struct FenwickTreeOneBasedIndexing
{
    vector<int> bit; // binary indexed tree
    int n;

    FenwickTreeOneBasedIndexing(int n)
    {
        this->n = n + 1;
        bit.assign(n + 1, 0);
    }

    FenwickTreeOneBasedIndexing(vector<int> a)
        : FenwickTreeOneBasedIndexing(a.size())
    {
        for (size_t i = 0; i < a.size(); i++)
            add(i, a[i]);
    }

    int sum(int idx)
    {
        int ret = 0;
        for (++idx; idx > 0; idx -= idx & -idx)
            ret += bit[idx];
        return ret;
    }

    int sum(int l, int r)
    {
        return sum(r) - sum(l - 1);
    }

    void add(int idx, int delta)
    {
        for (++idx; idx < n; idx += idx & -idx)
            bit[idx] += delta;
    }
};