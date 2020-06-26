#include <bits/stdc++.h>

using namespace std;

typedef long int li;
typedef long long int lli;
typedef vector<long long int> vlli;
typedef pair<lli, lli> plli;
typedef vector<int> vi;
typedef stack<long long int> slli;

bool comparator(plli const &p1, plli const &p2)
{
    return p1.first < p2.first;
}

void task()
{

    vector<plli> tasks;
    lli lenTasks;
    cin >> lenTasks;
    lli duration, deadline;
    for (lli i = 0; i < lenTasks; i++)
    {
        cin >> duration >> deadline;

        tasks.emplace_back(make_pair(duration, deadline));
    }
    sort(tasks.begin(), tasks.end(), comparator);
    lli reward = 0;
    lli time = 0;
    for (lli i = 0; i < lenTasks; i++)
    {
        time += tasks[i].first;
        reward += tasks[i].second - time;
    }
    cout << reward << '\n';
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    task();

    return 0;
}