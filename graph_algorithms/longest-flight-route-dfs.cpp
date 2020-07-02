#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef vector<lli> vi;

class Graph
{

    vector<vi> adj;
    vi distances;
    vi parents;
    lli nodes;
    vi longestPath;

public:
    Graph(lli _nodes)
    {
        this->nodes = _nodes;
        this->adj.resize(_nodes, vi{});
        this->distances.resize(_nodes, INT_MAX);
        this->parents.resize(_nodes, -1);
    }

    void addEdge(lli src, lli dst)
    {
        src--;
        dst--;
        if (find(this->adj[src].begin(), this->adj[src].end(), dst) == this->adj[src].end())
        {
            this->adj[src].emplace_back(dst);
        }
    }

    void dfs(lli node, lli parent, lli cost)
    {
        if (distances[node] > cost)
        {
            distances[node] = cost;
            parents[node] = parent;
        }

        for (auto nxt : this->adj[node])
        {
            this->dfs(nxt, node, cost - 1);
        }
    }

    void solve()
    {
        this->distances[0] = 0;
        this->dfs(0, -1, 0);

        if (this->distances[this->nodes - 1] == INT_MAX)
        {
            cout << "IMPOSSIBLE\n";
            return;
        }

        lli x = this->nodes - 1;
        stack<lli> path;
        cout << this->distances[this->nodes - 1] * -1 + 1 << '\n';
        while (x > -1)
        {
            path.push(x);
            x = parents[x];
        }

        while (!path.empty())
        {
            cout << path.top() + 1 << ' ';
            path.pop();
        }

        cout << '\n';
    }
};

void task()
{

    lli lenCities, lenFlights;
    cin >> lenCities >> lenFlights;
    Graph g(lenCities);
    lli a, b;
    for (lli i = 0; i < lenFlights; i++)
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