#include <bits/stdc++.h>

using namespace std;

typedef long int li;
typedef long long int lli;
typedef vector<long long int> vlli;
typedef vector<int> vi;
typedef stack<long long int> slli;

void task()
{

    lli lenValues;
    cin >> lenValues;

    vector<lli> response;

    lli value;

    stack<pair<lli, lli>> s;

    for (lli i = 0; i < lenValues; i++)
    {

        cin >> value;

        if (s.empty())
        {
            response.emplace_back(0);
            s.emplace(make_pair(value, i + 1));
            continue;
        }

        bool flag = false;

        while (!s.empty())
        {
            auto top = s.top();

            if (top.first < value)
            {
                response.emplace_back(top.second);
                s.emplace(make_pair(value, i + 1));
                flag = true;
                break;
            }
            else
            {
                s.pop();
            }
        }

        if (!flag)
        {
            response.emplace_back(0);
            s.emplace(make_pair(value, i + 1));
        }
    }

    for (auto ans : response)
    {
        cout << ans << ' ';
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