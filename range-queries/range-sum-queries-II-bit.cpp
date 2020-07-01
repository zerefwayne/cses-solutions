#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef vector<lli> vi;
typedef tuple<lli, lli> ii;
typedef tuple<lli, lli, lli> iii;

class FenwickTree
{

    vi BITree;
    lli n;

public:
    FenwickTree(lli n)
    {
        this->BITree.resize(n + 1, 0);
        this->n = n;
    }

    void add(lli pos, lli ele)
    {
        lli idx = pos;
        while (idx <= n)
        {
            BITree[idx] += ele;
            idx += idx & (-idx);
        }
    }

    lli prefixSum(lli idx)
    {

        lli sum = 0;

        while (idx)
        {
            sum += this->BITree[idx];
            idx -= idx & (-idx);
        }

        return sum;
    }

    lli rangeSum(lli a, lli b) {
        return this->prefixSum(b) - this->prefixSum(a-1);
    }
};

void task()
{

    lli lenNumbers, lenQueries;
    cin >> lenNumbers >> lenQueries;

    vi numbers(lenNumbers + 1);

    FenwickTree ft(lenNumbers);

    numbers[0] = 0;

    for (lli i = 1; i <= lenNumbers; i++)
    {
        cin >> numbers[i];
        ft.add(i, numbers[i]);
    }

    lli type, a, b;
    vi res;

    for (lli i = 0; i < lenQueries; i++)
    {
        cin >> type >> a >> b;
        if (type == 2)
        {
            res.emplace_back(ft.rangeSum(a, b));
        }
        else
        {
            ft.add(a, b - numbers[a]);
            numbers[a] = b;
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