#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef vector<lli> vi;

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

    void update(lli pos, lli ele)
    {

        lli curr = this->BITree[pos];
        lli diff = ele - curr;
        lli idx = pos;

        while (idx <= n)
        {
            BITree[idx] += diff;
            idx += idx & (-idx);
        }
    }

    lli getSum(lli idx)
    {

        lli sum = 0;

        while (idx)
        {
            sum += this->BITree[idx];
            idx -= idx & (-idx);
        }

        return sum;
    }

};