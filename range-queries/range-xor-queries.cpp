#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef vector<lli> vi;

class FenwickTree
{

    vi tree;
    lli nodes;

public:
    FenwickTree(lli _nodes)
    {
        nodes = _nodes;
        tree.resize(nodes + 1, 0);
    }

    void add(lli pos, lli val)
    {
        lli idx = pos;
        while (idx <= nodes)
        {
            tree[idx] ^= val;
            idx += idx & (-idx);
        }
    }

    lli prefixSum(lli pos)
    {
        lli sum = 0;
        lli idx = pos;
        while (idx)
        {
            sum ^= tree[idx];
            idx -= idx & (-idx);
        }
        return sum;
    }

    lli rangeSum(lli a, lli b)
    {
        return prefixSum(b) ^ prefixSum(a - 1);
    }
};

void task()
{
    lli lenNumbers, lenQueries;
    cin >> lenNumbers >> lenQueries;
    FenwickTree ft(lenNumbers);
    lli number;
    for (lli i = 1; i <= lenNumbers; i++)
    {
        cin >> number;
        ft.add(i, number);
    }
    vi res;
    lli a, b;
    for (lli i = 0; i < lenQueries; i++)
    {
        cin >> a >> b;
        res.emplace_back(ft.rangeSum(a, b));
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