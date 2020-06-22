#include <bits/stdc++.h>

using namespace std;

typedef long int li;
typedef long long int lli;
typedef pair<long long int, long long int> pllii;
typedef vector<long long int> vlli;
typedef vector<int> vi;
typedef stack<long long int> slli;

void task() {

    lli n, start, end;

    cin>>n;

    vector<pllii> movies;

    while(n--) {
        cin>>start>>end;
        movies.emplace_back(make_pair(end, start));
    }   

    sort(movies.begin(), movies.end()); 

    int maxMovies = 1;
    pllii lastWatched = movies[0];

    for(int i = 1; i < movies.size(); i++) {

        if(movies[i].second >= lastWatched.first) {
            maxMovies++;
            lastWatched = movies[i];
        }

    }

    cout<<maxMovies<<'\n';
    
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    task();

    return 0;
}