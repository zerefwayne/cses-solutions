#include <bits/stdc++.h>

using namespace std;

typedef long int li;
typedef long long int lli;
typedef vector<long long int> vlli;
typedef vector<int> vi;
typedef stack<long long int> slli;

class Graph
{

    vector<vector<lli>> adj;
    lli nodes;
    vector<bool> visited;

public:
    Graph(lli _nodes)
    {
        this->nodes = _nodes;
        this->adj.resize(_nodes, vector<lli>(0));
        this->visited.resize(_nodes, false);
    }

    void addEdge(lli src, lli dst)
    {

        src--;
        dst--;

        if (src == dst)
        {
            return;
        }
        this->adj[src].emplace_back(dst);
        this->adj[dst].emplace_back(src);
    }

    void calculateRoute()
    {

        lli src = 0;
        lli dst = this->nodes - 1;

        // node, distanceCovered
        queue<pair<lli, vector<lli>>> toVisit;

        toVisit.push(make_pair(src, vector<lli>(1, src)));
        this->visited[src] = true;

        while (!toVisit.empty())
        {
            auto top = toVisit.front();
            toVisit.pop();

            if (top.first == dst)
            {
                cout << top.second.size() << '\n';
                for (auto node : top.second)
                {
                    cout << node + 1 << ' ';
                }
                cout << '\n';
                return;
            }

            for (auto neighbour : this->adj[top.first])
            {
                if (!this->visited[neighbour])
                {
                    this->visited[neighbour] = true;
                    top.second.push_back(neighbour);
                    toVisit.push(make_pair(neighbour, top.second));
                    top.second.pop_back();
                }
            }
        }

        cout<<"IMPOSSIBLE\n";
    }
};

void task()
{

    lli n, m;
    cin>>n>>m;

    lli a, b;
    Graph g(n);

    for(lli i = 0; i < m; i++) {
        cin>>a>>b;
        g.addEdge(a, b);
    }

    g.calculateRoute();

}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    task();

    return 0;
}