#include <bits/stdc++.h>

using namespace std;

typedef long int li;
typedef long long int lli;

void task() {

    lli n;

    cin>>n;

    vector<lli> numbers(n, 0);

    for(int i = 0; i < n; i++) {
        cin>>numbers[i];
    }

    lli bestSum = numbers[0];
    lli currSum = numbers[0];

    for(int i = 1; i < n; i++) {
        currSum = max(numbers[i], currSum + numbers[i]);
        bestSum = max(bestSum, currSum);
    }

    cout<<bestSum<<'\n';
    
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    task();

    return 0;
}