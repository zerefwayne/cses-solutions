#include <bits/stdc++.h>

using namespace std;

typedef long int li;
typedef long long int lli;
typedef vector<long long int> vlli;
typedef vector<int> vi;
typedef stack<long long int> slli;

void task()
{

    lli lenNumbers, reqSum;
    cin >> lenNumbers >> reqSum;

    vector<pair<lli, lli>> numbers;

    lli temp;

    for (lli i = 1; i <= lenNumbers; i++) {
        cin >> temp;
        numbers.emplace_back(make_pair(temp, i));
    };

    if (lenNumbers < 3)
    {
        cout << "IMPOSSIBLE\n";
        return;
    }

    sort(numbers.begin(), numbers.end());

    lli i, j, k;
    lli sum;

    vector<lli> ans;

    for (i = 0; i < lenNumbers - 2; i++)
    {
        j = i + 1;
        k = lenNumbers - 1;

        while(j < k) {

            sum = numbers[i].first + numbers[j].first + numbers[k].first;

            if(sum == reqSum) {
                cout<<numbers[i].second<<' '<<numbers[j].second<<' '<<numbers[k].second<<'\n';
                return;
            } else if (sum < reqSum) {
                j++;
            } else {
                k--;
            }

        }
    }

    cout<<"IMPOSSIBLE\n";
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    task();

    return 0;
}