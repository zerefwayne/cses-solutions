// Got a TLE

#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef vector<lli> vi;

lli mod = 1e9 + 7;

class Graph
{

    vector<vi> adj;
    lli nodes;
    lli routes;

public:
    Graph(lli _nodes)
    {
        adj.resize(_nodes, vi{});
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
        if (node == nodes - 1)
        {
            routes = (routes + 1) % mod;
            return;
        }

        for (auto nxt : adj[node])
        {
            dfs(nxt);
        }
    }

    void solve()
    {
        dfs(0);
        cout << routes % mod << '\n';
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