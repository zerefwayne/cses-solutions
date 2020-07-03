#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef vector<lli> vi;

class Graph
{

    vi adj;
    vi cycle;
    lli nodes;

public:
    Graph(lli _nodes, vi _adj)
    {
        nodes = _nodes;
        adj.assign(_adj.begin(), _adj.end());
        cycle.resize(_nodes + 1, 0);
    }

    void preprocess()
    {

        for (lli i = 1; i <= nodes; i++)
        {
            lli x = adj[i];
            lli count = 0;
            bool failedToReturn = false;
            while (x != i)
            {
                count++;
                cycle[i]++;
                x = adj[x];
                if (count > nodes)
                {
                    failedToReturn = true;
                    break;
                }
            }
            cycle[i]++;
            if (failedToReturn)
            {
                cycle[i] = 0;
            }
        }
    }

    lli destinationNode(lli planet, lli distance)
    {

        lli x = planet;
        lli endgame = false;

        while (distance)
        {
            if (cycle[x] == 0 || endgame)
            {
                x = adj[x];
                distance--;
                continue;
            }

            if (cycle[x] == 1)
            {
                return x;
            }

            distance = distance % cycle[x];
            endgame = true;
        }

        return x;
    }
};

void task()
{
    lli lenPlanets, lenQueries;
    cin >> lenPlanets >> lenQueries;
    vi adj(lenPlanets + 1, 0);
    for (lli i = 1; i <= lenPlanets; i++)
    {
        cin >> adj[i];
    }
    Graph g(lenPlanets, adj);
    g.preprocess();
    lli planet, distance;
    for (lli i = 0; i < lenQueries; i++)
    {
        cin >> planet >> distance;
        cout << g.destinationNode(planet, distance) << '\n';
    }
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    task();
    return 0;
}