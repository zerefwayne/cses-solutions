#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef vector<lli> vi;

lli mod = 1e9 + 7;

class Graph
{

    vector<vi> adj;
    vi dp;
    vector<bool> visited;
    lli nodes;
    lli routes;

public:
    Graph(lli _nodes)
    {
        adj.resize(_nodes, vi{});
        dp.resize(_nodes, 0);
        visited.resize(_nodes, false);
        nodes = _nodes;
        routes = 0;
    }

    void addEdge(lli src, lli dst)
    {
        src--;
        dst--;
        if (find(adj[src].begin(), adj[src].end(), dst) == adj[src].end())
        {
            adj[src].emplace_back(dst);
        }
    }

    void dfs(lli node)
    {
        dp[node] = node == nodes - 1 ? 1 : 0;
        visited[node] = true;

        for (auto nxt : adj[node])
        {
            if (!visited[nxt])
            {
                dfs(nxt);
            }
            dp[node] = (dp[node] + dp[nxt]) % mod;
        }
    }

    void solve()
    {
        dfs(0);
        cout << dp[0] % mod << '\n';
    }
};

void task()
{

    lli numLevels, numTeleporters;
    cin >> numLevels >> numTeleporters;
    Graph g(numLevels);
    lli a, b;
    for (lli i = 0; i < numTeleporters; i++)
    {
        cin >> a >> b;
        g.addEdge(a, b);
    }
    g.solve();
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    task();

    return 0;
}