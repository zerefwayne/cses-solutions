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
    vector<bool> visited;
    vector<lli> path;
    lli pre;

public:
    Graph(lli nodes)
    {
        this->adj.resize(nodes, vector<lli>{});
        this->nodes = nodes;
        this->visited.resize(nodes, false);
    }

    void addDirectedEdge(lli src, lli dst)
    {

        if (src == dst)
        {
            return;
        }

        this->adj[src].emplace_back(dst);
    }

    void addUndirectedEdge(lli src, lli dst)
    {

        if (src == dst)
        {
            return;
        }

        this->adj[src].emplace_back(dst);
        this->adj[dst].emplace_back(src);
    }

    bool dfs(lli node, lli parent)
    {

        this->visited[node] = true;

        this->path.push_back(node);

        for (auto neighbour : this->adj[node])
        {

            if (!this->visited[neighbour])
            {

                if (dfs(neighbour, node))
                {
                    return true;
                }
            }
            else if (neighbour != parent)
            {

                this->path.push_back(neighbour);
                this->pre = neighbour;
                return true;
            }
        }

        this->path.pop_back();
        return false;
    }

    void searchRoundTrips()
    {

        bool flag = false;

        for (lli i = 0; i < this->nodes; i++)
        {

            if (!this->visited[i])
            {

                if (this->dfs(i, -1))
                {

                    flag = true;
                    break;
                }
            }
        }

        if (flag)
        {

            lli j = 0;

            for (j = 0; j < this->path.size(); j++)
            {

                if (this->path[j] == this->pre)
                {
                    break;
                }
            }

            cout << this->path.size() - j << '\n';

            for (lli i = j; i < this->path.size(); i++)
            {

                cout << this->path[i] + 1 << ' ';
            }

            cout << '\n';
        }
        else
        {

            cout << "IMPOSSIBLE\n";
        }
    }
};

void task()
{
    lli cities, roads;
    cin >> cities >> roads;
    Graph g(cities);
    lli a, b;
    for (lli i = 0; i < roads; i++)
    {
        cin >> a >> b;
        g.addUndirectedEdge(a - 1, b - 1);
    }

    g.searchRoundTrips();
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    task();

    return 0;
}