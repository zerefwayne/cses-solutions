#include <bits/stdc++.h>

using namespace std;

typedef long int li;
typedef long long int lli;
typedef vector<long long int> vlli;
typedef pair<lli, lli> plli;
typedef vector<int> vi;
typedef stack<long long int> slli;

void task()
{

    lli lenNumbers, lenWindow;
    cin >> lenNumbers >> lenWindow;

    vector<lli> numbers(lenNumbers);

    multiset<lli> window;

    for (lli i = 0; i < lenNumbers; i++)
    {
        cin >> numbers[i];
    }

    for (lli i = 0; i < lenNumbers; i++)
    {
        window.insert(numbers[i]);

        if (i < lenWindow - 1)
        {
            continue;
        }

        auto median = window.begin();
        advance(median, lenWindow / 2);
        if (lenWindow % 2 == 0)
        {
            lli first = *median;
            advance(median, 1);
            lli second = *median;
            cout << floor((first + second) / 2.0) << ' ';
        }
        else
        {

            cout << *median << ' ';
        }
        window.erase(window.find(numbers[i - lenWindow + 1]));
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