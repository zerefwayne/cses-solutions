#include <bits/stdc++.h>

using namespace std;

typedef long int li;
typedef long long int lli;
typedef vector<long long int> vlli;
typedef vector<int> vi;
typedef stack<long long int> slli;

vector<pair<lli, lli>> directions = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};

void dfs(vector<vector<bool>> &floor, lli x, lli y, lli n, lli m) {

    floor[x][y] = false;

    for(auto dir : directions) {

        lli nx = x + dir.first;
        lli ny = y + dir.second;

        if(nx < 0 || nx >= n || ny < 0 || ny >= m) {
            continue;
        }

        if(floor[nx][ny]) {
            dfs(floor, nx, ny, n, m);
        }

    }

}

void task() {

    lli n, m;
    cin>>n>>m;

    vector<vector<bool>> floor(n, vector<bool>(m, false));

    char cell;

    for(int i = 0; i < n; i++) {
        for(int j = 0; j < m; j++) {
            cin>>cell;
            if (cell == '.') {
                floor[i][j] = true;
            }
        }
    }

    lli rooms = 0;

    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++) {

            if(floor[i][j]) {
                rooms++;
                dfs(floor, i, j, n, m);
            }

        }
    }

    cout<<rooms<<'\n';
    
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    task();

    return 0;
}