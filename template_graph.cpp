#include <bits/stdc++.h>

using namespace std;

typedef long int li;
typedef long long int lli;
typedef vector<long long int> vlli;
typedef vector<int> vi;
typedef stack<long long int> slli;
typedef pair<lli, lli> plli;

class Graph {

    vector<vector<lli>> adj;
    lli nodes;
    vector<lli> assigned;

    public:
        Graph(lli nodes) {
            this->adj.resize(nodes, vector<lli>{});
            this->nodes = nodes;
            this->assigned.resize(nodes, 0);
        }

        void addDirectedEdge(lli src, lli dst) {

            if(src == dst) {
                return;
            }

            this->adj[src].emplace_back(dst);

        }

        void addUndirectedEdge(lli src, lli dst) {

            if(src == dst) {
                return;
            }

            this->adj[src].emplace_back(dst);
            this->adj[dst].emplace_back(src);

        }

        void solve() {

            

        }



};

void task() {

    
    
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    task();

    return 0;
}