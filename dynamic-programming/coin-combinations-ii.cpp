#include <bits/stdc++.h>

using namespace std;

typedef int lli;
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

    dp[0] = 1;

    for (auto coin : coins)
    {
        for (lli i = 1; i <= desiredSum; i++)
        {
            if (coin <= i)
            {
                dp[i] = (dp[i] + dp[i - coin]) % mod;
            }
        }
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