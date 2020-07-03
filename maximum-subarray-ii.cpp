#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef vector<lli> vi;
typedef tuple<lli, lli> ii;
typedef tuple<lli, lli, lli> iii;

void task()
{

    lli lenNumbers, minLength, maxLength;
    cin >> lenNumbers >> minLength >> maxLength;
    vi numbers(lenNumbers);
    for (lli i = 0; i < lenNumbers; i++)
        cin >> numbers[i];
    lli currLength = 0;
    lli currSum = 0;
    lli bestSum = LONG_LONG_MIN;
    for (lli i = 0; i < lenNumbers; i++)
    {

        lli num = numbers[i];

        if (num > currSum + num)
        {
            currSum = num;
            currLength = 1;
        }
        else
        {
            currSum += num;
            currLength++;
        }

        if (currLength > maxLength)
        {
            currSum = num;
            currLength = 1;
        }

        if (currLength >= minLength && currLength <= maxLength)
        {
            bestSum = max(currSum, bestSum);
        }
    }

    cout<<bestSum<<'\n';
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    task();

    return 0;
}