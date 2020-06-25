#include <bits/stdc++.h>

using namespace std;

typedef long int li;
typedef long long int lli;
typedef vector<long long int> vlli;
typedef vector<int> vi;
typedef stack<long long int> slli;

void task()
{

    lli lenMachines, lenProducts;
    cin >> lenMachines >> lenProducts;
    vector<lli> machines(lenMachines);
    for (lli i = 0; i < lenMachines; i++)
        cin >> machines[i];
    lli minTime = *min_element(machines.begin(), machines.end());
    lli minTimeRequired = minTime * lenProducts;

    lli productsCreated = 0;

    lli l = 0;
    lli r = minTimeRequired;

    while (l < r)
    {

        lli m = l + (r - l) / 2;

        productsCreated = 0;

        for (lli i = 0; i < lenMachines; i++)
        {
            productsCreated += floor(m / machines[i]);
        }

        if (productsCreated == lenProducts)
        {
            cout << m << '\n';
            return;
        }
        else if (productsCreated < lenProducts)
        {
            l = m + 1;
        }
        else
        {
            r = m;
        }
    }

    cout << l << '\n';
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    task();

    return 0;
}