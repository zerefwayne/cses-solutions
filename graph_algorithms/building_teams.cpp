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

public:
    Graph(lli nodes)
    {
        this->adj.resize(nodes, vector<lli>{});
        this->nodes = nodes;
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

    void checkBipartite()
    {

        queue<pair<lli, lli>> q;

        vector<lli> colors(this->nodes, 0);

        for (lli i = 0; i < this->nodes; i++)
        {
            if (colors[i] == 0)
            {
                q.push(make_pair(i, 1));

                while (!q.empty())
                {

                    auto top = q.front();
                    q.pop();
                    colors[top.first] = top.second;
                    lli nextColor = top.second == 2 ? 1 : 2;

                    for (auto neighbour : this->adj[top.first])
                    {
                        if (colors[neighbour] == 0)
                        {
                            q.push({neighbour, nextColor});
                        }
                        else if (colors[neighbour] != nextColor)
                        {
                            cout << "IMPOSSIBLE\n";
                            return;
                        }
                    }
                }
            }
        }

        for (auto team : colors)
        {
            cout << team << ' ';
        }

        cout << '\n';
    }
};

void task()
{

    lli pupils, friendships;
    cin>>pupils>>friendships;

    Graph g(pupils);

    lli a, b;

    for(lli i = 0; i < friendships; i++) {
        cin>>a>>b;
        g.addUndirectedEdge(a-1, b-1);
    }

    g.checkBipartite();

}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    task();

    return 0;
}