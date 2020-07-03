#include <bits/stdc++.h>

using namespace std;

typedef int lli;
typedef vector<lli> vi;

lli mod = 1e9 + 7;

void task()
{

    lli x;
    cin >> x;
    vi dp(x + 1, 0);

    lli faces = 6;

    for (lli i = 1; i <= x; i++)
    {
        if (i <= faces)
        {
            dp[i] = (lli)pow(2, i - 1);
            continue;
        }

        for (lli f = 1; f <= faces; f++)
        {
            dp[i] = (dp[i] + dp[i - f]) % mod;
        }
    }

    cout << dp[x] % mod << '\n';
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    task();

    return 0;
}