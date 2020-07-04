#include <bits/stdc++.h>

using namespace std;

typedef int lli;
typedef pair<lli, lli> ii;
typedef vector<lli> vi;
typedef vector<ii> vii;
typedef vector<vector<lli>> vvi;

lli numBooks, maxPrice;
vvi dp;
vii books;

bool comparator(ii const &p1, ii const &p2)
{
    return p1.first > p2.first;
}

void task()
{

    cin >> numBooks >> maxPrice;
    books = vii(numBooks);
    dp = vvi(numBooks, vi(maxPrice + 1, 0));
    for (lli i = 0; i < numBooks; i++)
    {
        cin >> books[i].first;
    }
    for (lli i = 0; i < numBooks; i++)
    {
        cin >> books[i].second;
    }

    sort(books.begin(), books.end(), greater<ii>());

    for (lli i = 0; i < numBooks; i++)
    {
        for (lli j = books[i].first; j <= maxPrice; j++)
        {

            if (i == 0)
            {
                dp[i][j] = books[i].second;
            }
            else
            {

                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - books[i].first] + books[i].second);
            }
        }
    }

    cout << dp[numBooks - 1][maxPrice] << '\n';
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    task();

    return 0;
}
