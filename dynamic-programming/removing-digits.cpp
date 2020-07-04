#include <bits/stdc++.h>

using namespace std;

typedef int lli;
typedef vector<lli> vi;

lli maxDigit(lli n)
{

    lli maxi = 0;

    while (n)
    {
        maxi = max(maxi, n % 10);
        n /= 10;
    }

    return maxi;
}

void task()
{
    lli num;
    cin >> num;

    lli steps = 0;

    while (num > 0)
    {
        steps++;
        num -= maxDigit(num);
    }

    cout << steps << '\n';
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    task();

    return 0;
}