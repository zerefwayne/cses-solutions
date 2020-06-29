#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef vector<lli> vi;
typedef tuple<lli, lli> ii;
typedef tuple<lli, lli, lli> iii;

lli INF = 1e10;

class Graph
{

    vector<vector<ii>> adj;
    vector<iii> edges;
    lli nodes;
    vi distances;

public:
    Graph(lli _nodes)
    {
        this->nodes = _nodes;
        this->adj.resize(_nodes, vector<ii>{});
        this->distances.resize(_nodes, INF);
    }

    void addDirectedEdge(lli src, lli dst, lli weight)
    {
        this->adj[src].emplace_back(make_tuple(dst, weight));
        this->edges.emplace_back(make_tuple(src, dst, weight));
    }

    void solve()
    {

        // Bellman ford detecting negative cycles

        this->distances[0] = 0;
        vi parents(this->nodes, -1);

        lli n = this->nodes;

        lli src, dst, wt;

        lli x = -1;

        for (lli i = 0; i < n; i++)
        {
            x = -1;
            for (auto edge : this->edges)
            {

                tie(src, dst, wt) = edge;
                if (distances[src] + wt < distances[dst])
                {
                    distances[dst] = distances[src] + wt;
                    parents[dst] = src;
                    x = dst;
                }
            }
        }

        if (x == -1)
        {
            cout << "NO\n";
            return;
        }

        for (lli i = 0; i < n; i++)
        {
            x = parents[x];
        }

        vi cycle;

        for (lli v = x;; v = parents[v])
        {
            cycle.push_back(v);
            if (v == x && cycle.size() > 1)
            {
                break;
            }
        }

        reverse(cycle.begin(), cycle.end());

        cout << "YES\n";

        for (auto node : cycle)
        {
            cout << node + 1 << ' ';
        }

        cout << '\n';
    }
};

void task()
{

    lli lenNodes, lenEdges;
    cin >> lenNodes >> lenEdges;
    Graph g(lenNodes);
    lli src, dst, wt;

    for (lli i = 0; i < lenEdges; i++)
    {
        cin >> src >> dst >> wt;
        g.addDirectedEdge(src - 1, dst - 1, wt);
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