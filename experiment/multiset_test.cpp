#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

void task() {

    vector<int> tickets;

    tickets.emplace_back(1);
    tickets.emplace_back(14);
    tickets.emplace_back(12);

    sort(tickets.begin(), tickets.end(), greater<int>());

    cout<<*lower_bound(tickets.begin(), tickets.end(), 13, greater<int>())<<'\n';

    
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    task();

    return 0;
}