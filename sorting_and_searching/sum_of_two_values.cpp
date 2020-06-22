#include <bits/stdc++.h>

using namespace std;

typedef long int li;
typedef long long int lli;
typedef vector<long long int> vlli;
typedef vector<int> vi;
typedef stack<long long int> slli;

void task() {

    lli n, sum, curr;

    cin>>n>>sum;

    vector<pair<lli, lli>> numbers;

    for(lli i = 0; i < n; i++) {
        cin>>curr;
        numbers.emplace_back(make_pair(curr, i+1));
    }

    sort(numbers.begin(), numbers.end());

    lli l = 0;
    lli r = numbers.size() - 1;

    while(l < r) {

        lli curr = numbers[l].first + numbers[r].first;

        if(curr == sum ) {
            printf("%lld %lld\n", numbers[l].second, numbers[r].second);
            return;
        } else if(curr < sum) {
            l++;
        } else {
            r--;
        }

    }

    printf("IMPOSSIBLE\n");
    
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    task();

    return 0;
}