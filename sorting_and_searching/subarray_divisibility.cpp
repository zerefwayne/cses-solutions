#include <bits/stdc++.h>

using namespace std;

typedef long int li;
typedef long long int lli;
typedef vector<long long int> vlli;
typedef vector<int> vi;
typedef stack<long long int> slli;

void task()
{

    lli lenNumbers;
    cin >> lenNumbers;

    lli cumSum = 0;
    vector<lli> mod(lenNumbers, 0);

    lli temp;

    for(lli i = 0; i < lenNumbers; i++) {
        cin>>temp;
        cumSum += temp;
        mod[((cumSum % lenNumbers) + lenNumbers ) % lenNumbers]++;
    }

    lli ans = 0;

    for(lli i = 0; i < lenNumbers; i++) {
        if(mod[i] > 1) {
            ans += (mod[i] * (mod[i] - 1))/2;
        }
    }

    ans += mod[0];

    cout<<ans<<'\n';
    
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    task();

    return 0;
}