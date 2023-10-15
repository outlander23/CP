class SegmentTree
{
private:
    int n;
    vector<int> tree;

    int gcd(int a, int b)
    {
        return __gcd(a, b);
    }

public:
    SegmentTree(int size, const vector<int> &arr)
    {
        n = size;                 // Assign the size to the member variable n
        tree.resize(4 * (n + 5)); // Size for a complete binary tree
        build(arr, 1, 1, n);
    }
    void build(const vector<int> &arr, int node, int left, int right)
    {
        if (left == right)
        {
            tree[node] = arr[left];
        }
        else
        {
            int mid = (left + right) / 2;
            build(arr, 2 * node, left, mid);
            build(arr, 2 * node + 1, mid + 1, right);
            tree[node] = gcd(tree[2 * node], tree[2 * node + 1]);
        }
    }

    int query(int node, int left, int right, int l, int r)
    {
        if (l > right || r < left)
        {
            return 0; // Return an appropriate default value
        }
        if (l <= left && right <= r)
        {
            return tree[node];
        }
        int mid = (left + right) / 2;
        int left_gcd = query(2 * node, left, mid, l, r);
        int right_gcd = query(2 * node + 1, mid + 1, right, l, r);
        return gcd(left_gcd, right_gcd);
    }

    int query(int l, int r)
    {
        return query(1, 1, n, l, r);
    }

    void update(int node, int left, int right, int idx, int val)
    {
        if (left == right)
        {
            tree[node] = val;
        }
        else
        {
            int mid = (left + right) / 2;
            if (idx <= mid)
            {
                update(2 * node, left, mid, idx, val);
            }
            else
            {
                update(2 * node + 1, mid + 1, right, idx, val);
            }
            tree[node] = gcd(tree[2 * node], tree[2 * node + 1]);
        }
    }

    void update(int idx, int val)
    {
        update(1, 1, n, idx, val);
    }
};
