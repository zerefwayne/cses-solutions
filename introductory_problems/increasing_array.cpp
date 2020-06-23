#include <bits/stdc++.h>

using namespace std;

typedef long int li;
typedef long long int lli;
typedef vector<long long int> vlli;
typedef vector<int> vi;
typedef stack<long long int> slli;

void task()
{

    lli lenNumbers;
    cin >> lenNumbers;

    lli turns = 0;

    lli prev = 0;
    lli number;

    for (lli i = 0; i < lenNumbers; i++)
    {

        cin >> number;

        if (i == 0)
        {
            prev = number;
            continue;
        }

        if (number <= prev)
        {
            turns += prev - number;
        } else {
            prev = number;
        }
    }

    cout << turns << '\n';
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    task();

    return 0;
}