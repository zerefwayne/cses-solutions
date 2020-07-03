#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef vector<lli> vi;

void task()
{

    lli lenCoins, desiredSum;
    cin >> lenCoins >> desiredSum;
    vi coins(lenCoins);
    for (lli i = 0; i < lenCoins; i++)
        cin >> coins[i];
    vi dp(desiredSum + 1, INT_MAX);

    dp[0] = 0;

    for (lli i = 1; i <= desiredSum; i++)
    {
        for (auto coin : coins)
        {
            if (coin <= i)
            {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    if (dp[desiredSum] == INT_MAX)
    {
        cout << "-1\n";
    }
    else
    {
        cout << dp[desiredSum] << '\n';
    }
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    task();

    return 0;
}