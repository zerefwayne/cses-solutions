#include <bits/stdc++.h>

using namespace std;

typedef long int li;
typedef long long int lli;
typedef vector<long long int> vlli;
typedef vector<int> vi;
typedef stack<long long int> slli;

void task() {

    lli lenSticks;

    cin>>lenSticks;

    vector<lli> sticks(lenSticks);

    for(lli i = 0; i < lenSticks; i++) {
        cin>>sticks[i];
    }

    sort(sticks.begin(), sticks.end());

    lli median = sticks[lenSticks/2];

    lli cost = 0;

    for(lli i = 0; i < lenSticks; i++) {
        cost += abs(sticks[i] - median);
    }

    cout<<cost<<'\n';



}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    task();

    return 0;
}