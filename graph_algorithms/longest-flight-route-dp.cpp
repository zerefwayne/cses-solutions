#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef vector<lli> vi;

class Graph
{

    vector<vi> adj;
    vector<bool> visited;
    lli nodes;
    vi dp;

public:
    Graph(lli _nodes)
    {
        this->nodes = _nodes;
        this->adj.resize(_nodes, vi{});
        this->dp.resize(_nodes, INT_MIN);
        this->visited.resize(_nodes, false);
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

    void dfs(lli node)
    {
        if (visited[node])
            return;
        visited[node] = true;
        dp[node] = (node != nodes - 1) ? INT_MIN : 0;
        for (auto nxt : adj[node])
        {
            dfs(nxt);
            dp[node] = max(dp[node], dp[nxt] + 1);
        }
    }

    void solve()
    {
        this->dfs(0);

        if (dp[0] < 0)
        {
            cout << "IMPOSSIBLE\n";
            return;
        }

        cout << dp[0] + 1 << '\n';

        int x = 0;

        while (x != nodes - 1)
        {

            cout << x + 1 << ' ';

            for (auto nxt : adj[x])
            {

                if (dp[nxt] == dp[x] - 1)
                {
                    x = nxt;
                    break;
                }
            }
        }

        cout << nodes << '\n';
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