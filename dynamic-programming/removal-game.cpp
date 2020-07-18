#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef vector<lli> vi;
typedef tuple<lli, lli> ii;
typedef tuple<lli, lli, lli> iii;

void task()
{

    lli n;
    cin >> n;
    vector<lli> nums(n, 0);

    for (lli i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    vector<vector<pair<lli, lli>>> dp(n, vector<pair<lli, lli>>(n, make_pair(0, 0)));

    for (lli length = 1; length <= n; length++)
    {

        for (lli i = 0; i <= n - length; i++)
        {

            lli x = i;
            lli y = i + length - 1;

            if (x == y)
            {
                dp[x][y] = make_pair(nums[x], 0);
                continue;
            }

            if (dp[x][y - 1].second + nums[y] > dp[x + 1][y].second + nums[x])
            {

                dp[x][y].first = dp[x][y - 1].second + nums[y];
                dp[x][y].second = dp[x][y - 1].first;
            }
            else
            {
                dp[x][y].first = dp[x + 1][y].second + nums[x];
                dp[x][y].second = dp[x + 1][y].first;
            }
        }
    }

    cout << dp[0][n - 1].first << '\n';
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    task();

    return 0;
}