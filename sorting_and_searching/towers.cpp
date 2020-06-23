#include <bits/stdc++.h>

using namespace std;

typedef long int li;
typedef long long int lli;
typedef vector<long long int> vlli;
typedef vector<int> vi;
typedef stack<long long int> slli;

void task()
{

    lli lenCubes;
    cin >> lenCubes;
    multiset<lli> stacks;
    lli cube;
    for (lli i = 0; i < lenCubes; i++)
    {

        cin >> cube;

        auto loc = stacks.upper_bound(cube);

        if (loc == stacks.end())
        {
            stacks.insert(cube);
        }
        else
        {
            stacks.erase(loc);
            stacks.insert(cube);
        }
    }

    cout << stacks.size() << '\n';
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    task();

    return 0;
}