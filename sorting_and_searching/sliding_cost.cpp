#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef vector<lli> vlli;
typedef tuple<lli, lli> ii;
typedef tuple<lli, lli, lli> iii;

void task()
{

    lli lenNumbers, lenWindow;
    cin >> lenNumbers >> lenWindow;

    vector<lli> res;

    vector<lli> numbers;

    multiset<lli> minHeap;
    multiset<lli, greater<lli>> maxHeap;

    lli number;
    lli currentMedian = 0;

    for (lli i = 0; i < lenNumbers; i++)
    {
        cin >> number;
        numbers.emplace_back(number);

        if (i >= lenWindow)
        {

            lli cost = 0;

            for (lli j = i - lenWindow; j < i; j++)
            {
                cost += abs(numbers[j] - currentMedian);
            }

            res.emplace_back(cost);

            lli toBeRemoved = numbers[i - lenWindow];
            if (toBeRemoved <= currentMedian)
            {
                maxHeap.erase(maxHeap.find(toBeRemoved));
            }
            else
            {
                minHeap.erase(minHeap.find(toBeRemoved));
            }
        }

        maxHeap.insert(number);
        minHeap.insert(*maxHeap.begin());
        maxHeap.erase(maxHeap.begin());
        if (maxHeap.size() < minHeap.size())
        {
            maxHeap.insert(*minHeap.begin());
            minHeap.erase(minHeap.begin());
        }
        currentMedian = *maxHeap.begin();
    }

    lli cost = 0;

    for (lli j = lenNumbers - lenWindow; j < lenNumbers; j++)
    {
        cost += abs(numbers[j] - currentMedian);
    }

    res.emplace_back(cost);

    for (auto r : res)
    {
        cout << r << ' ';
    }

    cout << '\n';
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    task();

    return 0;
}