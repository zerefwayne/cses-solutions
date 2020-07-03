#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef vector<lli> vi;

lli mod = 1e9 + 7;

void task()
{

    lli lenCoins, desiredSum;
    cin >> lenCoins >> desiredSum;
    vi coins(lenCoins);
    for (lli i = 0; i < lenCoins; i++)
        cin >> coins[i];
    vi dp(desiredSum + 1, 0);
    sort(coins.begin(), coins.end());

    dp[0] = 1;

    for (lli i = coins[0]; i <= desiredSum; i++)
    {
        for (auto coin : coins)
        {
            if (coin <= i)
            {
                dp[i] += dp[i - coin];
            }
            else
            {
                break;
            }
        }
        dp[i] = dp[i] % mod;
    }

    cout << dp[desiredSum] % mod << '\n';
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    task();

    return 0;
}