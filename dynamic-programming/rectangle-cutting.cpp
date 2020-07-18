#include <bits/stdc++.h>

using namespace std;

int minimumCuts(int a, int b)
{

    vector<vector<int>> dp(a + 1, vector<int>(b + 1, 0));

    for (int i = 1; i <= a; i++)
    {

        for (int j = 1; j <= b; j++)
        {

            if (i ^ j)
            {
                dp[i][j] = 1e9;
            }

            for (int k = 1; k < i; k++)
            {

                dp[i][j] = min(dp[i][j], dp[k][j] + dp[i - k][j] + 1);
            }

            for (int k = 1; k < j; k++)
            {

                dp[i][j] = min(dp[i][j], dp[i][k] + dp[i][j - k ] + 1);
            }
        }
    }

    return dp[a][b];
}

void task()
{
    int a, b;
    cin >> a >> b;
    cout << minimumCuts(a, b) << '\n';
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    task();

    return 0;
}