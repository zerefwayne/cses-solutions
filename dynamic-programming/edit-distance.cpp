#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

void task()
{

    string a, b;
    cin >> a >> b;

    int lenA = a.length();
    int lenB = b.length();

    vector<vector<int>> dp(lenA + 1, vector<int>(lenB + 1, 0));

    for (int i = 0; i <= lenA; i++)
    {

        for (int j = 0; j <= lenB; j++)
        {

            if (i == 0 || j == 0)
            {
                dp[i][j] = max(i, j);
                continue;
            }

            if (a[i-1] == b[j-1])
            {
                dp[i][j] = dp[i - 1][j - 1];
                continue;
            }

            dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1])) + 1;
        }
    }

    cout << dp[lenA][lenB] << '\n';
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    task();

    return 0;
}