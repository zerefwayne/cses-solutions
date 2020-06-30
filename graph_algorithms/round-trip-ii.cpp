#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef vector<lli> vi;
typedef tuple<lli, lli> ii;
typedef tuple<lli, lli, lli> iii;

class Graph
{

    vector<vi> adj;
    vector<bool> white;
    vector<bool> gray;
    vector<bool> black;
    vi parents;
    lli nodes;

public:
    Graph(lli _nodes)
    {
        this->nodes = _nodes;
        this->adj.resize(this->nodes, vi{});
        this->white.resize(this->nodes, true);
        this->gray.resize(this->nodes, false);
        this->black.resize(this->nodes, false);
        this->parents.resize(this->nodes, -1);
    }

    bool isAvailable(lli src)
    {
        return this->white[src];
    }

    void addEdge(lli src, lli dst)
    {
        this->adj[src - 1].emplace_back(dst - 1);
    }

    bool dfs(lli node, lli parent)
    {

        this->white[node] = false;
        this->gray[node] = true;
        this->parents[node] = parent;

        for (auto nxt : this->adj[node])
        {

            if (this->black[nxt])
            {
                continue;
            }
            else if (this->white[nxt])
            {
                if (this->dfs(nxt, node))
                {
                    return true;
                }
            }
            else if (this->gray[nxt])
            {

                // cycle detected
                vi cycle;

                lli x = node;

                while (x != nxt)
                {
                    cycle.push_back(x);
                    x = this->parents[x];
                }

                if (cycle.size() == 0)
                {
                    continue;
                }

                cycle.push_back(nxt);
                cycle.push_back(node);

                reverse(cycle.begin(), cycle.end());

                cout << cycle.size() << '\n';
                for (auto n : cycle)
                {
                    cout << n + 1 << ' ';
                }
                cout << '\n';

                return true;
            }
        }

        this->gray[node] = false;
        this->black[node] = true;
        return false;
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
    for (lli i = 0; i < lenCities; i++)
    {
        if (g.isAvailable(i))
        {
            if (g.dfs(i, -1))
            {
                return;
            }
        }
    }
    cout<<"IMPOSSIBLE\n";
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    task();

    return 0;
}