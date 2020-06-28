#include <bits/stdc++.h>

using namespace std;

typedef long int li;
typedef long long int lli;
typedef vector<long long int> vlli;
typedef vector<int> vi;
typedef stack<long long int> slli;
typedef pair<lli, lli> plli;

class Graph
{

    vector<vector<plli>> adjFor, adjRev;
    vector<tuple<lli, lli, lli>> edges;
    lli nodes;

public:
    Graph(lli nodes)
    {
        this->adjFor.resize(nodes, vector<plli>{});
        this->adjRev.resize(nodes, vector<plli>{});
        this->nodes = nodes;
    }

    void addDirectedEdge(lli src, lli dst, lli weight)
    {

        if (src == dst)
        {
            return;
        }

        this->adjFor[src].emplace_back(make_pair(dst, weight));
        this->adjRev[dst].emplace_back(make_pair(src, weight));
        this->edges.emplace_back(make_tuple(src, dst, weight));
    }

    void dijkstra(vector<vector<plli>> &adj, vector<lli> &distance, lli src)
    {
        priority_queue<plli, vector<plli>, greater<plli>> pq;
        distance[src] = 0;
        pq.push(make_pair(0, src));
        while (!pq.empty())
        {
            auto top = pq.top();
            pq.pop();
            if (top.first > distance[top.second])
                continue;
            for (auto v : adj[top.second])
            {
                if (distance[v.first] > top.first + v.second)
                {
                    distance[v.first] = top.first + v.second;
                    pq.push(make_pair(distance[v.first], v.first));
                }
            }
        }
    }

    void solve()
    {

        vector<lli> distanceFor(this->nodes, LONG_LONG_MAX);
        vector<lli> distanceRev(this->nodes, LONG_LONG_MAX);

        this->dijkstra(this->adjFor, distanceFor, 0);
        this->dijkstra(this->adjRev, distanceRev, this->nodes - 1);

        lli result = LONG_LONG_MAX;
        lli src, dst, weight;

        for (auto edge : this->edges)
        {
            tie(src, dst, weight) = edge;
            if (distanceRev[dst] == LONG_LONG_MAX || distanceFor[src] == LONG_LONG_MAX)
            {
                continue;
            }
            result = min(result, distanceFor[src] + distanceRev[dst] + (lli)floor(weight / 2));
        }
        cout << result << '\n';
    }
};

void task()
{

    lli cities, flights;
    cin >> cities >> flights;

    lli src, dst, weight;

    Graph g(cities);

    for (lli i = 0; i < flights; i++)
    {
        cin >> src >> dst >> weight;
        g.addDirectedEdge(src - 1, dst - 1, weight);
    }

    g.solve();
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    task();

    return 0;
}