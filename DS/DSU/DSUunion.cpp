/* union by size */
struct dsu
{

    int n;
    vector<int> parent, size;

    void init(int rn)
    {
        n = rn + 5;
        parent = vector<int>(n);
        size = vector<int>(n);
        for (int i = 0; i < n; i++)
            make_set(i);
    }

    void make_set(int v)
    {
        parent[v] = v;
        size[v] = 1;
    }

    int find_set(int v)
    {
        if (v == parent[v])
            return v;
        return parent[v] = find_set(parent[v]);
    }

    void union_sets(int a, int b)
    {
        a = find_set(a);
        b = find_set(b);
        if (a != b)
        {
            if (size[a] < size[b])
                swap(a, b);
            parent[b] = a;
            size[a] += size[b];
        }
    }

    int getSize(int v)
    {
        return size[find_set(v)];
    }

    void merge(int a, int b)
    {
        union_sets(a, b);
    }

    int getParrent(int n) { return find_set(n); }
};