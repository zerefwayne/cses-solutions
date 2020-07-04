#include <bits/stdc++.h>

using namespace std;

typedef int lli;
typedef tuple<lli, lli> ii;
typedef vector<lli> vi;
typedef vector<vi> vvi;
typedef vector<bool> vb;
typedef vector<vb> vvb;

lli n;
vvb grid;
vvb visited;
vvi dp;

vector<ii> directions{make_tuple(1, 0), make_tuple(0, 1)};

lli mod = 1e9 + 7;

void dfs(lli x, lli y)
{
    visited[x][y] = true;

    if (x == n - 1 && y == n - 1)
    {
        dp[x][y] = 1;
        return;
    }

    for (auto dir : directions)
    {

        lli dx, dy;
        tie(dx, dy) = dir;

        lli nx = x + dx;
        lli ny = y + dy;

        if (nx < 0 || nx >= n || ny < 0 || ny >= n)
        {
            continue;
        }

        if (!visited[nx][ny])
        {

            if (grid[nx][ny])
            {

                dfs(nx, ny);
            }
        }
        dp[x][y] += dp[nx][ny];
    }
    dp[x][y] = dp[x][y] % mod;
}

void task()
{

    cin >> n;
    grid = vvb(n, vb(n, true));
    visited = vvb(n, vb(n, false));
    dp = vvi(n, vi(n, 0));

    char ch;

    for (lli i = 0; i < n; i++)
    {
        for (lli j = 0; j < n; j++)
        {
            cin >> ch;
            if (ch == '*')
            {
                grid[i][j] = false;
            }
        }
    }

    for (lli i = 0; i < n; i++)
    {
        for (lli j = 0; j < n; j++)
        {
            if (!visited[i][j])
            {

                if (grid[i][j])
                {
                    dfs(i, j);
                }
            }
        }
    }

    cout << dp[0][0] % mod << '\n';
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    task();

    return 0;
}