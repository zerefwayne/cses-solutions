#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef vector<lli> vi;
typedef tuple<lli, lli> ii;
typedef tuple<lli, lli, lli> iii;

void task()
{

    set<int> res;
    int lenNums;

    cin >> lenNums;
    vector<int> nums(lenNums);

    for (int i = 0; i < lenNums; i++)
    {
        cin >> nums[i];
    }

    for (int i = 0; i < lenNums; i++)
    {
        int num = nums[i];

        set<int> newNums;

        for (auto it = res.begin(); it != res.end(); it++)
        {
            newNums.insert(*it + num);
        }

        newNums.insert(num);

        res.insert(newNums.begin(), newNums.end());
    }

    cout << res.size() << '\n';
    for (auto it = res.begin(); it != res.end(); it++)
    {
        cout << *it << ' ';
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