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

    lli lenStream;
    cin >> lenStream;
    priority_queue<lli> maxHeap;
    priority_queue<lli, vector<lli>, greater<lli>> minHeap;

    lli currentMedian = 0;

    lli number;

    vector<lli> ans;

    cin >> currentMedian;
    lenStream--;
    ans.emplace_back(currentMedian);

    while (lenStream--)
    {

        cin >> number;

        if (maxHeap.size() > minHeap.size())
        {

            if (number < currentMedian)
            {
                minHeap.push(maxHeap.top());
                maxHeap.pop();
                maxHeap.push(number);
            }
            else
            {
                minHeap.push(number);
            }

            currentMedian = (lli)floor((maxHeap.top() + minHeap.top()) / 2.0);
        }
        else if (maxHeap.size() == minHeap.size())
        {

            if (number < currentMedian)
            {

                maxHeap.push(number);
                currentMedian = maxHeap.top();
            }
            else
            {
                minHeap.push(number);
                currentMedian = minHeap.top();
            }
        }
        else
        {

            if (number > currentMedian)
            {

                maxHeap.push(minHeap.top());
                minHeap.pop();
                minHeap.push(number);
            }
            else
            {
                maxHeap.push(number);
            }

            currentMedian = (lli)floor((maxHeap.top() + minHeap.top()) / 2.0);
        }

        ans.emplace_back(currentMedian);
    }

    for(auto num: ans) {
        cout<<num<<'\n';
    }

}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    task();

    return 0;
}