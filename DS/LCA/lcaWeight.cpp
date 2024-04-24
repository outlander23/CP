struct LCA
{
    int N;    // Number of nodes
    int logN; // Logarithm base 2 of N
    vector<int> depth;
    vector<vector<int>> parent;
    vector<vector<int>> weight;

    LCA(int n)
    {
        init(n);
    }

    void init(int n)
    {
        N = n + 5;
        logN = log2(N) + 2;
        depth.resize(N);
        parent.assign(N, vector<int>(logN, -1));
        weight.assign(N, vector<int>(logN, 0));
    }

    void dfs(int node, int par, vector<vector<pair<int, int>>> &adj)
    {
        parent[node][0] = par;
        for (int i = 1; i < logN; ++i)
        {
            if (parent[node][i - 1] != -1)
            {
                parent[node][i] = parent[parent[node][i - 1]][i - 1];
                weight[node][i] = max(weight[node][i - 1], weight[parent[node][i - 1]][i - 1]);
            }
        }

        for (auto &[child, w] : adj[node])
        {
            if (child != par)
            {
                depth[child] = depth[node] + 1;
                weight[child][0] = w;
                dfs(child, node, adj);
            }
        }
    }

    int query(int u, int v)
    {
        if (depth[u] < depth[v])
            swap(u, v);

        int diff = depth[u] - depth[v];
        int ans = 0;

        for (int i = 0; i < logN; ++i)
        {
            if (diff & (1 << i))
            {
                ans = max(ans, weight[u][i]);
                u = parent[u][i];
            }
        }

        if (u == v)
            return ans;

        for (int i = logN - 1; i >= 0; --i)
        {
            if (parent[u][i] != parent[v][i])
            {
                ans = max(ans, max(weight[u][i], weight[v][i]));
                u = parent[u][i];
                v = parent[v][i];
            }
        }

        return max({ans, weight[u][0], weight[v][0]});
    }
};