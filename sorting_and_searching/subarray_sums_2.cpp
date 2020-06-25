#include <bits/stdc++.h>

using namespace std;

typedef long int li;
typedef long long int lli;
typedef vector<long long int> vlli;
typedef vector<int> vi;
typedef stack<long long int> slli;

void task()
{

    lli lenNumbers, reqSum;
    cin >> lenNumbers >> reqSum;
    map<lli, lli> occurences;

    occurences[0]++;

    lli num;
    lli currSum = 0;
    lli ans = 0;

    for (lli i = 0; i < lenNumbers; i++)
    {
        cin >> num;
        currSum += num;
        ans += occurences[currSum - reqSum];
        occurences[currSum]++;
    }

    cout<<ans<<'\n';
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    task();

    return 0;
}