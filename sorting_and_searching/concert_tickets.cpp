#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

void task()
{

    lli n, m, temp;

    cin >> n >> m;

    vector<lli> tickets;

    while (n--)
    {
        cin >> temp;
        tickets.emplace_back(temp);
    }

    sort(tickets.begin(), tickets.end());

    for (auto price : tickets)
    {
        printf("%lld ", price);
    }

    printf("\n");

    vector<lli> ans;

    while (m--)
    {
        cin >> temp;
        auto it = lower_bound(tickets.begin(), tickets.end(), temp);

        if (it == tickets.end())
        {
            ans.emplace_back(-1);
        }
        else
        {
            ans.emplace_back(*it);
            tickets.erase(it);
        }
    }

    for (auto price : ans)
    {
        printf("%lld ", price);
    }

    printf("\n");
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    task();

    return 0;
}