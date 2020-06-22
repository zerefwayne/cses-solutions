#include <bits/stdc++.h>

using namespace std;

typedef long int li;
typedef long long int lli;
typedef vector<long long int> vlli;
typedef vector<int> vi;
typedef stack<long long int> slli;

vector<tuple<lli, lli, char>> directions = {{0, -1, 'L'}, {1, 0, 'D'}, {0, 1, 'R'}, {-1, 0, 'U'}};

class Node
{

public:
    lli x;
    lli y;
    lli distance;
    string path;

    Node(int x, int y, int distance, string path)
    {
        this->x = x;
        this->y = y;
        this->path = path;
        this->distance = distance;
    }
};

void task()
{

    lli n, m;

    cin >> n >> m;

    vector<vector<char>> grid(n, vector<char>(m));
    vector<vector<bool>> visited(n, vector<bool>(m, false));

    pair<lli, lli> start, end;

    for (lli i = 0; i < n; i++)
    {
        for (lli j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
            {
                start = make_pair(i, j);
            }
            if (grid[i][j] == 'B')
            {
                end = make_pair(i, j);
            }
        }
    }

    queue<Node> pq;

    pq.push(Node(start.first, start.second, 0, ""));

    while (!pq.empty())
    {

        Node top = pq.front();

        pq.pop();

        
        if (make_pair(top.x, top.y) == end)
        {
            cout << "YES\n";
            cout << top.distance << '\n';
            cout << top.path << '\n';
            return;
        }

        for (auto direction : directions)
        {

            lli nx = top.x + get<0>(direction);
            lli ny = top.y + get<1>(direction);

            if (nx < 0 || nx >= n || ny < 0 || ny >= m || visited[nx][ny] || grid[nx][ny] == '#')
            {
                continue;
            }

            string newPath = top.path;
            newPath.push_back(get<2>(direction));

            lli newDistance = top.distance + 1;

            pq.push(Node(nx, ny, newDistance, newPath));
            visited[nx][ny] = true;
        }
    }

    cout << "NO\n";
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    task();

    return 0;
}