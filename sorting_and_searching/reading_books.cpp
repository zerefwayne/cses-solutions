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

    lli lenBooks;
    cin >> lenBooks;

    vlli books(lenBooks, 0);
    lli totalTime = 0;
    lli maxTime = 0;

    for (lli i = 0; i < lenBooks; i++)
    {
        cin >> books[i];
        totalTime += books[i];
        maxTime = max(maxTime, books[i]);
    }

    if (maxTime * 2 > totalTime)
    {
        cout << maxTime * 2 << '\n';
    }
    else
    {
        cout << totalTime << '\n';
    }
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    task();

    return 0;
}
