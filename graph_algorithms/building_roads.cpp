#include <bits/stdc++.h>

using namespace std;

typedef long int li;
typedef long long int lli;
typedef vector<long long int> vlli;
typedef vector<int> vi;
typedef stack<long long int> slli;

class Graph
{
public:
    vector<vector<lli>> adj;
    vector<bool> visited;
    lli nodes;

    Graph(lli nodes)
    {
        this->nodes = nodes;
        this->adj.resize(nodes);
        this->visited.resize(nodes);
    }

    void addEdge(lli src, lli dst)
    {

        if (src == dst)
        {
            return;
        }

        this->adj[src].push_back(dst);
        this->adj[dst].push_back(src);
    }

    void dfs(lli node)
    {
        this->visited[node] = true;

        for (auto newNode : this->adj[node])
        {
            if (!this->visited[newNode])
            {
                dfs(newNode);
            }
        }
    }

    void connectedComponents()
    {
        lli components = 0;

        vector<lli> starts;

        for (lli i = 0; i < this->nodes; i++)
        {

            if (!this->visited[i])
            {
                components++;
                starts.emplace_back(i);
                dfs(i);
            }
        }

        cout << components - 1 << '\n';

        if (components > 1)
        {

            for (int i = 1; i < starts.size(); i++)
            {

                cout << starts[i - 1] + 1 << ' ' << starts[i] + 1 << '\n';
            }
        }
    }
};

void task()
{

    lli cities, roads;

    cin >> cities >> roads;

    Graph g(cities);

    lli a, b;

    while (roads--)
    {
        cin >> a >> b;
        g.addEdge(a - 1, b - 1);
    }

    g.connectedComponents();
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    task();

    return 0;
}