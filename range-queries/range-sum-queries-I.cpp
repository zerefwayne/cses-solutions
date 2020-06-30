#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef vector<lli> vi;
typedef tuple<lli, lli> ii;
typedef tuple<lli, lli, lli> iii;

void task()
{

    lli lenNumbers, lenQueries;
    cin >> lenNumbers >> lenQueries;
    vi numbers(lenNumbers);
    for (lli i = 0; i < lenNumbers; i++)
    {
        cin >> numbers[i];
    }
    vi prefix(lenNumbers, numbers[0]);
    for (lli i = 1; i < lenNumbers; i++)
    {
        prefix[i] = prefix[i - 1] + numbers[i];
    }
    lli a, b;
    vi res;
    for (lli i = 0; i < lenQueries; i++)
    {
        cin >> a >> b;
        a--;
        b--;
        if (a == 0)
        {
            res.emplace_back(prefix[b]);
        }
        else
        {
            res.emplace_back(prefix[b] - prefix[a - 1]);
        }
    }
    for (auto r : res)
    {
        cout << r << '\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    task();

    return 0;
}