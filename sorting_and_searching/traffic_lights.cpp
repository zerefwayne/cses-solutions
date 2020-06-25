#include <bits/stdc++.h>

using namespace std;

typedef long int li;
typedef long long int lli;
typedef vector<long long int> vlli;
typedef vector<int> vi;
typedef stack<long long int> slli;

/*

METHOD 1: Multiset using custom operator sorts according to distance

struct Comparator
{
    bool operator()(pair<lli, lli> const &p1, pair<lli, lli> const &p2)
    {
        return (p1.second - p1.first) > (p2.second - p2.first);
    }
};

void task()
{

    lli x, n;
    cin >> x >> n;

    multiset<pair<lli, lli>, Comparator> streets;

    streets.insert(make_pair(0, x));

    lli location;

    vector<lli> response;

    for (lli i = 0; i < n; i++)
    {

        cin >> location;

        auto it = streets.begin();

        for (; it != streets.end(); it++)
        {
            if (location > (*it).first && location < (*it).second)
            {
                break;
            }
        }

        lli start = (*it).first;
        lli end = (*it).second;

        streets.erase(it);

        streets.insert(make_pair(start, location));
        streets.insert(make_pair(location, end));

        auto top = *streets.begin();

        response.emplace_back(top.second - top.first);
    }

    for (auto res : response)
    {
        cout << res << ' ';
    }

    cout << '\n';
}

*/

void task()
{

    lli x, n;
    cin >> x >> n;

    set<lli> points{0, x};
    multiset<lli> lengths{x};

    lli point;

    for (int i = 0; i < n; i++)
    {
        cin >> point;

        auto it = points.upper_bound(point);

        auto left = *prev(it);
        auto right = *it;

        lengths.erase(lengths.find(right - left));

        lengths.insert(point - left);
        lengths.insert(right - point);

        points.insert(it, point);

        cout << *lengths.rbegin() << ' ';
    }

    cout << '\n';
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    task();

    return 0;
}