#include <bits/stdc++.h>

using namespace std;

typedef long int li;
typedef long long int lli;
typedef vector<long long int> vlli;
typedef vector<int> vi;
typedef stack<long long int> slli;

bool check(lli mid, vlli &numbers, lli buckets)
{

    lli sum = 0;
    lli count = 0;

    for (auto num : numbers)
    {

        if (num > mid)
        {
            return false;
        }

        sum += num;

        if (sum > mid)
        {
            count++;
            sum = num;
        }
    }

    count++;

    return count <= buckets;
}

void task()
{

    lli lenNumbers, lenBuckets;
    cin >> lenNumbers >> lenBuckets;

    vlli numbers(lenNumbers);

    for (lli i = 0; i < lenNumbers; i++)
        cin >> numbers[i];

    lli l = *max_element(numbers.begin(), numbers.end());
    lli h = accumulate(numbers.begin(), numbers.end(), 0);
    lli mid;
    lli ans = INT_MAX;

    if (lenBuckets == 1)
    {
        cout << h << '\n';
        return;
    }

    while (l <= h)
    {

        lli mid = l + (h - l) / 2;

        if (check(mid, numbers, lenBuckets))
        {
            ans = min(ans, mid);
            h = mid - 1;
        }
        else
        {
            l = mid + 1;
        }
    }

    cout << ans << '\n';
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    task();

    return 0;
}