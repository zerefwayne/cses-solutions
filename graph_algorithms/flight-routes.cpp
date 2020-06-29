#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef vector<lli> vi;
typedef tuple<lli, lli, lli> iii;
typedef tuple<lli, lli> ii;

class Graph
{

    vector<vector<ii>> adj;
    lli nodes;
    multiset<ii> result;
    vector<vi> distances;
    vi path;

public:
    Graph(lli _nodes)
    {
        this->nodes = _nodes;
        this->adj.resize(_nodes, vector<ii>{});
        this->distances.resize(_nodes, vi{});
    }

    void addDirectedEdge(lli src, lli dst, lli wt)
    {
        this->adj[src].emplace_back(make_tuple(dst, wt));
    }

    void solve(lli k)
    {

        priority_queue<ii, vector<ii>, greater<ii>> pq;
        pq.push(make_tuple(0, 0));
        while (pq.size())
        {
            lli u, c;
            tie(c, u) = pq.top();
            pq.pop();
            if (this->distances[u].size() >= k)
            {
                continue;
            }
            this->distances[u].push_back(c);
            lli v, w;
            for (auto edge : this->adj[u])
            {
                tie(v, w) = edge;
                pq.push(make_tuple(c + w, v));
            }
        }
        for (lli i = 0; i < k; i++)
        {
            cout << distances[this->nodes - 1][i] << ' ';
        }
        cout << '\n';
    }
};

void task()
{
    lli lenCities, lenFlights, k;
    cin >> lenCities >> lenFlights >> k;
    Graph g(lenCities);
    lli src, dst, wt;
    for (lli i = 0; i < lenFlights; i++)
    {
        cin >> src >> dst >> wt;
        g.addDirectedEdge(src - 1, dst - 1, wt);
    }
    g.solve(k);
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    task();

    return 0;
}