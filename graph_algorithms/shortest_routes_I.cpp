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

    vector<vector<plli>> adj;
    lli nodes;

public:
    Graph(lli nodes)
    {
        this->adj.resize(nodes, vector<plli>{});
        this->nodes = nodes;
    }

    void addDirectedEdge(lli src, lli dst, lli weight)
    {

        if (src == dst)
        {
            return;
        }

        this->adj[src].emplace_back(make_pair(dst, weight));
    }


    void dijkstra()
    {

        vector<lli> distances(this->nodes, LONG_LONG_MAX);

        distances[0] = 0;

        priority_queue<plli, vector<plli>, greater<plli>> pq;

        pq.push(make_pair(0, 0));

        while (!pq.empty())
        {

            auto top = pq.top();
            pq.pop();

            lli u = top.second;

            // important for speeding up

            if (top.first > distances[u])
            {
                continue;
            }

            for (auto neighbour : this->adj[u])
            {

                lli v = neighbour.first;
                lli w = neighbour.second;

                if (distances[v] > distances[u] + w)
                {
                    distances[v] = distances[u] + w;
                    pq.push(make_pair(distances[v], v));
                }
            }
        }

        for (auto distance : distances)
        {
            cout << distance << ' ';
        }

        cout << '\n';
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

    g.dijkstra();
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    task();

    return 0;
}