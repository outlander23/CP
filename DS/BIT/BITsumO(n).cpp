// ONE BASE INDEXING
struct BIT
{
    int size;
    vector<int> bit;
    BIT(int n, vector<int> &a) : size(n + 5), bit(n + 5)
    {
        for (int i = 1; i <= n; i++)
        {
            bit[i] += a[i];
            if (i + (i & -i) <= n)
                bit[i + (i & -i)] += bit[i];
        }
    }

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
