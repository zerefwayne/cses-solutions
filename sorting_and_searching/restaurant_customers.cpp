#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;

void task()
{

    lli customers;
    cin >> customers;

    lli currentCount = 0;
    lli maxCount = 0;

    vector<pair<lli, lli>> infos;

    // 0 arrival 1 departure

    lli entry, exit;

    while (customers--)
    {

        cin >> entry >> exit;
        infos.emplace_back(make_pair(entry, 0));
        infos.emplace_back(make_pair(exit, 1));
    }

    sort(infos.begin(), infos.end());

    for (auto info : infos)
    {

        if (info.second == 0)
        {

            currentCount++;
            maxCount = max(currentCount, maxCount);
        }
        else
        {
            currentCount--;
        }
    }

    cout<<maxCount<<'\n';
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    task();

    return 0;
}