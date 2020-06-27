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

    vector<vector<lli>> adj;
    lli nodes;

public:
    Graph(lli nodes)
    {
        this->adj.resize(nodes, vector<lli>(nodes, LONG_LONG_MAX));

        for (lli i = 0; i < nodes; i++)
        {
            this->adj[i][i] = 0;
        }

        this->nodes = nodes;
    }

    void addUndirectedEdge(lli src, lli dst, lli weight)
    {

        if (src == dst)
        {
            return;
        }

        if (this->adj[src][dst] > weight)
        {
            this->adj[src][dst] = weight;
            this->adj[dst][src] = weight;
        }
    }

    void floydWarshall()
    {

        for (lli k = 0; k < this->nodes; k++)
        {

            for (lli i = 0; i < this->nodes; i++)
            {

                for (lli j = 0; j < this->nodes; j++)
                {

                    if (this->adj[i][k] == LONG_LONG_MAX || this->adj[k][j] == LONG_LONG_MAX)
                    {
                        continue;
                    }

                    if (this->adj[i][k] + this->adj[k][j] < this->adj[i][j])
                    {

                        this->adj[i][j] = this->adj[i][k] + this->adj[k][j];
                    }
                }
            }
        }
    }

    lli shortestDistance(lli src, lli dst)
    {

        if (this->adj[src][dst] == LONG_LONG_MAX)
        {
            return -1;
        }
        return this->adj[src][dst];
    }
};

void task()
{

    lli cities, roads, lenQueries;
    cin >> cities >> roads >> lenQueries;

    Graph g(cities);

    lli src, dst, weight;

    for (lli i = 0; i < roads; i++)
    {
        cin >> src >> dst >> weight;
        g.addUndirectedEdge(src - 1, dst - 1, weight);
    }

    g.floydWarshall();

    vector<lli> res;

    for (lli i = 0; i < lenQueries; i++)
    {
        cin >> src >> dst;
        res.emplace_back(g.shortestDistance(src - 1, dst - 1));
    }

    for (auto ans : res)
    {
        cout << ans << '\n';
    }
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    task();

    return 0;
}