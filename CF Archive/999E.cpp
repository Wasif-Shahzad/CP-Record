#include <bits/stdc++.h>
using namespace std;

vector<bool> visited; // keeps track of which vertices are already visited

// runs depth first search starting at vertex v.
// each visited vertex is appended to the output vector when dfs leaves it.
void dfs(int v, vector<vector<int>> const& adj, vector<int> &output) {
    visited[v] = true;
    for (auto u : adj[v])
        if (!visited[u])
            dfs(u, adj, output);
    output.push_back(v);
}

// input: adj -- adjacency list of G
// output: components -- the strongy connected components in G
// output: adj_cond -- adjacency list of G^SCC (by root vertices)
void strongly_connected_components(vector<vector<int>> const& adj,
                                  vector<vector<int>> &components,
                                  vector<vector<int>> &adj_cond,
                                  vector<int>& roots) {
    int n = adj.size();
    components.clear(), adj_cond.clear();

    vector<int> order; // will be a sorted list of G's vertices by exit time

    visited.assign(n, false);

    // first series of depth first searches
    for (int i = 0; i < n; i++)
        if (!visited[i])
            dfs(i, adj, order);

    // create adjacency list of G^T
    vector<vector<int>> adj_rev(n);
    for (int v = 0; v < n; v++)
        for (int u : adj[v])
            adj_rev[u].push_back(v);

    visited.assign(n, false);
    reverse(order.begin(), order.end());

    roots.assign(n, 0); // gives the root vertex of a vertex's SCC

    // second series of depth first searches
    for (auto v : order)
        if (!visited[v]) {
            std::vector<int> component;
            dfs(v, adj_rev, component);
            components.push_back(component);
            int root = *component.begin();
            for (auto u : component)
                roots[u] = root;
        }

    // add edges to condensation graph
    adj_cond.assign(n, {});
    for (int v = 0; v < n; v++)
        for (auto u : adj[v])
            if (roots[v] != roots[u])
                adj_cond[roots[v]].push_back(roots[u]);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, s;
    cin >> n >> m >> s;
    s--;
    vector<vector<int>> g(n);
    for(int i = 0; i < m; i++) {
        int u, v;
        cin >> u >> v;
        u--, v--;
        g[u].push_back(v);
    }
    vector<vector<int>> comps, adj_cond;
    vector<int> roots;
    strongly_connected_components(g, comps, adj_cond, roots);
    vector<set<int>> adj(n);
    for(int i = 0; i < n; i++) {
        adj[i] = set<int>(adj_cond[i].begin(), adj_cond[i].end());
    }
    vector<int> order, vis(n, 0);
    auto topo = [&] (int u, auto&& self) -> void {
        vis[u] = 1;
        for(int c: adj[u]) {
            if (vis[c]) continue;
            self(c, self);
        }
        order.push_back(u);
    };
    for(int i = 0; i < n; i++) {
        if (roots[i] == i && !vis[i]) topo(i, topo);
    }
    vis.assign(n, 0);
    reverse(order.begin(), order.end());
    int cnt = 0;
    auto dfs = [&] (int u, auto&& self) -> void {
        vis[u] = 1;
        for(int c: adj[u]) {
            if(vis[c]) continue;
            self(c, self);
        }
    };
    for(int i: order) {
        if(!vis[i]) {
            dfs(i, dfs);
            cnt++;
        }
    }
    vector<int> in(n, 0);
    for(int i = 0; i < n; i++) {
        for(int c: adj[i]) in[c]++;
    }
    cout << cnt - 1 + (in[roots[s]] > 0) << '\n';
}
