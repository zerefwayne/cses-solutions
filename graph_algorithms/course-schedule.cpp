#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef vector<lli> vi;

class Graph
{

    lli nodes;
    vector<vi> adj;
    stack<lli> order;
    vector<bool> white;
    vector<bool> gray;
    vector<bool> black;

public:
    Graph(lli _nodes)
    {
        this->nodes = _nodes;
        this->adj.resize(_nodes, vi{});
        this->white.resize(_nodes, true);
        this->gray.resize(_nodes, false);
        this->black.resize(_nodes, false);
    }

    void addEdge(lli src, lli dst)
    {
        this->adj[src - 1].emplace_back(dst - 1);
    }

    bool dfs(lli node)
    {
        this->white[node] = false;
        this->gray[node] = true;

        for (auto nxt : this->adj[node])
        {
           if(this->white[nxt]) {
               if(this->dfs(nxt) == false) {
                   return false;
               }
           } else if (this->black[nxt]) {
               continue;
           } else if(this->gray[nxt]) {
               return false;
           }
        }

        this->order.push(node);
        this->gray[node] = false;
        this->black[node] = true;
        return true;
    }

    void solve()
    {
        for (lli i = 0; i < this->nodes; i++)
        {
            if (this->white[i])
            {
                if(dfs(i) == false) {
                    cout<<"IMPOSSIBLE\n";
                    return;
                }
            }
        }

        while (!this->order.empty())
        {
            cout << this->order.top() + 1 << ' ';
            this->order.pop();
        }

        cout << '\n';
    }
};

void task()
{

    lli lenCourses, lenPrereqs;
    cin >> lenCourses >> lenPrereqs;
    Graph g(lenCourses);
    lli pre, nxt;
    for (lli i = 0; i < lenPrereqs; i++)
    {
        cin >> pre >> nxt;
        g.addEdge(pre, nxt);
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