#include <bits/stdc++.h>
#define GO       \
    cin.tie(0);  \
    cout.tie(0); \
    ios::sync_with_stdio(0);
typedef long long ll;
using namespace std;
const int N = 2e5 + 50;
vector<int> adj[N];
int ST[N][4], par[N], depth[N], sz[N];
int ind[N], comp[N];
int dep[N];
vector<int> v[N];
int n, q;

void DFS(int u = 1, int p = 1, int d = 0)
{
    par[u] = p;
    depth[u] = d;
    sz[u] = 1;
    for (int v : adj[u])
    {
        if (v == p)
            continue;
        DFS(v, u, d + 1);
        sz[u] += sz[v];
    }
}

void DFS2(int u = 1, int p = 1, int c = 1)
{
    int mx = 0, nd;
    ind[u] = v[c].size();
    v[c].push_back(u);
    comp[u] = c;
    for (int v : adj[u])
    {
        if (v == p)
            continue;
        if (sz[v] > mx)
        {
            mx = sz[v];
            nd = v;
        }
    }
    for (int v : adj[u])
    {
        if (v == p)
            continue;
        if (v == nd)
            DFS2(v, u, c);
        else
        {
            ST[v][0] = c;
            dep[v] = dep[c] + 1;
            DFS2(v, u, v);
        }
    }
}

int jump(int u, int k)
{
    if (!k)
        return u;
    if (k > depth[u])
        return -1;
    if (ind[u] >= k)
        return v[comp[u]][ind[u] - k];
    k -= ind[u];
    u = comp[u];
    int dpt = depth[u];
    for (int i = 3; i >= 0; i--)
    {
        int nC = ST[u][i];
        if (dpt - depth[nC] < k)
            u = nC;
    }
    k -= dpt - depth[u] + 1;
    u = par[u];
    return v[comp[u]][ind[u] - k];
}

int LCA(int u, int v)
{
    if (comp[u] == comp[v])
    {
        if (depth[u] < depth[v])
            return u;
        return v;
    }
    if (dep[comp[u]] < dep[comp[v]])
        swap(u, v);
    u = comp[u];
    if (dep[comp[u]] > dep[comp[v]])
    {
        for (int i = 3; i >= 0; i--)
        {
            int nU = ST[u][i];
            if (dep[nU] > dep[comp[v]])
                u = nU;
        }
        u = par[u];
        if (comp[u] == comp[v])
        {
            if (depth[u] < depth[v])
                return u;
            return v;
        }
        u = comp[u];
    }
    v = comp[v];
    assert(dep[u] == dep[v]);
    for (int i = 3; i >= 0; i--)
    {
        int nU = ST[u][i];
        int nV = ST[v][i];
        if (nU != nV)
            u = nU, v = nV;
    }
    if (depth[u] < depth[v])
        return par[u];
    return par[v];
}

int main()
{
    GO
            cin >>
        n >> q;
    for (int i = 2; i <= n; i++)
    {
        int a;
        cin >> a;
        adj[a].push_back(i);
        adj[i].push_back(a);
    }
    DFS();
    DFS2();
    ST[1][0] = 1;
    for (int i = 1; i < 4; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int u = ST[j][i - 1];
            ST[j][i] = ST[u][i - 1];
        }
    }
    while (q--)
    {
        int u, v;
        cin >> u >> v;
        cout << LCA(u, v) << '\n';
    }
    return 0;
}