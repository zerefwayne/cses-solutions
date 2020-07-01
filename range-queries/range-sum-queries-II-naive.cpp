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

    vi numbers(lenNumbers + 1);

    numbers[0] = 0;

    for (lli i = 1; i <= lenNumbers; i++)
    {
        cin >> numbers[i];
    }

    vi prefix(lenNumbers + 1, 0);

    for (lli i = 1; i <= lenNumbers; i++)
    {
        prefix[i] = prefix[i - 1] + numbers[i];
    }

    lli type, a, b;
    vi res;

    for (lli i = 0; i < lenQueries; i++)
    {
        cin >> type >> a >> b;
        if (type == 2)
        {
            res.emplace_back(prefix[b] - prefix[a - 1]);
        }
        else
        {
            lli diff = b - numbers[a];
            numbers[a] = b;

            for (lli j = a; j <= lenNumbers; j++)
            {
                prefix[j] += diff;
            }
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