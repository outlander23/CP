struct LCA
{
    int N, logN;
    vector<int> parr;
    vector<int> depth;
    vector<vector<int>> adj;
    vector<vector<int>> table;

    void init(int n)
    {
        N = n + 5;
        logN = log2(N) + 2;
        parr.resize(N);
        depth.resize(N);
        adj.resize(N);
        table.resize(logN, vector<int>(N));
    }

    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        // adj[v].push_back(u);
    }

    void dfs(int node, int p, int d = 0)
    {
        parr[node] = p;
        depth[node] = d;
        table[0][node] = p;
        for (auto child : adj[node])
            if (child != p)
                dfs(child, node, d + 1);
    }

    void build()
    {
        dfs(1, 0);
        for (int k = 1; k < logN; k++)
            for (int i = 1; i < N; i++)
                table[k][i] = table[k - 1][table[k - 1][i]];
    }

    // return the kth ancestor of the node
    int walk(int i, int k)
    {
        for (int j = 0; j < logN; j++)
            if (k & (1ll << j))
                i = table[j][i];
        return i;
    }

    // return the lca of the nodes
    int lca(int u, int v)
    {
        int depth_u = depth[u];
        int depth_v = depth[v];
        if (depth_u > depth_v)
            u = walk(u, depth_u - depth_v);
        else if (depth_v > depth_u)
            v = walk(v, depth_v - depth_u);

        if (u == v)
        {
            return u;
        }
        else
        {
            for (int i = logN - 1; i >= 0; i--)
            {
                if (table[i][u] != table[i][v])
                {
                    u = table[i][u];
                    v = table[i][v];
                }
            }
            return table[0][u];
        }
    }

    // return the depth of the node
    int depth_of_node(int node)
    {
        return depth[node];
    }

    // dist between two nodes
    int dist(int u, int v)
    {
        return depth[u] + depth[v] - 2 * depth[lca(u, v)];
    }
    void clear()
    {
        N = 0;
        logN = 0;
        parr.clear();
        depth.clear();
        for (int i = 0; i < N; i++)
        {
            adj[i].clear();
            table[i].clear();
        }
        adj.clear();
        table.clear();
    }
    // Add this destructor to your LCA struct
    ~LCA()
    {
        clear();
    }
};