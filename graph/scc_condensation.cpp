// zero indexing
class SCC
{
public:
    SCC(int n) : n(n)
    {
        adj.resize(n);
        adj_t.resize(n);
    }

    void add_edge(int u, int v)
    {
        adj[u].push_back(v);
        adj_t[v].push_back(u);
    }

    int solve()
    {
        visited.assign(n, false);
        for (int i = 0; i < n; ++i)
        {
            if (!visited[i])
                dfs1(i);
        }
        visited.assign(n, false);
        reverse(order.begin(), order.end());
        components.clear();
        component.resize(n);
        int c = 0;
        for (int i : order)
        {
            if (!visited[i])
            {
                components.push_back({});
                dfs2(i, c);
                c++;
            }
        }

        adj_condensation.resize(c);
        for (int v = 0; v < n; v++)
        {
            for (int u : adj[v])
            {
                if (component[v] != component[u])
                    adj_condensation[component[v]].push_back(component[u]);
            }
        }

        return c;
    }

    void dfs1(int v)
    {
        visited[v] = true;
        for (int u : adj[v])
        {
            if (!visited[u])
                dfs1(u);
        }
        order.push_back(v);
    }

    void dfs2(int v, int c)
    {
        visited[v] = true;
        components.back().push_back(v);
        component[v] = c;
        for (int u : adj_t[v])
        {
            if (!visited[u])
                dfs2(u, c);
        }
    }

    int n;
    std::vector<std::vector<int>> adj, adj_t, components, adj_condensation;
    std::vector<bool> visited;
    std::vector<int> order, component;
};

// use case
// https://codeforces.com/contest/999/submission/228852832

// one base indexing
// tested but it is better to use zero indexing
// try to use zero indexing
class SCC
{
public:
    // Constructor: Initialize the SCC algorithm with 'n' nodes.
    SCC(int n) : n(n)
    {
        adj.resize(n + 1);
        adjT.resize(n + 1);
    }

    // Add a directed edge from node 'u' to node 'v'.
    void addEdge(int u, int v)
    {
        adj[u].push_back(v);
        adjT[v].push_back(u);
    }

    // Find strongly connected components and return the number of components.
    int find()
    {
        // Step 1: Perform the first DFS traversal to fill the 'order' vector.
        visited.assign(n + 1, false);
        for (int i = 1; i <= n; ++i)
        {
            if (!visited[i])
                dfs1(i);
        }

        // Step 2: Reset visited flags, reverse the 'order', and find components.
        visited.assign(n + 1, false);
        reverse(order.begin(), order.end());
        components.clear();
        component.resize(n + 1);
        int c = 0;
        for (int i : order)
        {
            if (!visited[i])
            {
                components.push_back({});
                dfs2(i, c);
                c++;
            }
        }

        // Step 3: Build the condensed graph and return the number of components.
        condensed.resize(c);
        for (int v = 1; v <= n; v++)
        {
            for (int u : adj[v])
            {
                if (component[v] != component[u])
                    condensed[component[v]].push_back(component[u]);
            }
        }

        return c;
    }

    // DFS traversal for the first pass to fill the 'order'.
    void dfs1(int v)
    {
        visited[v] = true;
        for (int u : adj[v])
        {
            if (!visited[u])
                dfs1(u);
        }
        order.push_back(v);
    }

    // DFS traversal for the second pass to find components.
    void dfs2(int v, int c)
    {
        visited[v] = true;
        components.back().push_back(v);
        component[v] = c;
        for (int u : adjT[v])
        {
            if (!visited[u])
                dfs2(u, c);
        }
    }

    int n;
    std::vector<std::vector<int>> adj, adjT, components, condensed;
    std::vector<bool> visited;
    std::vector<int> order, component;
};
