#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef vector<lli> vi;
typedef tuple<lli, lli> ii;
typedef tuple<lli, lli, lli> iii;

void preprocess(vector<vector<lli>> &sparse, vi &input)
{

    lli n = input.size();

    for (lli i = 0; i < n; i++)
    {
        sparse[i][0] = i;
    }

    for (lli j = 1; j <= (lli)log2(n); j++)
    {

        for (lli i = 0; i + (lli)pow(2, j) - 1 < n; i++)
        {

            if (input[sparse[i][j - 1]] < input[sparse[i + pow(2, j - 1)][j - 1]])
            {

                sparse[i][j] = sparse[i][j - 1];
            }
            else
            {
                sparse[i][j] = sparse[i + pow(2, j - 1)][j - 1];
            }
        }
    }
}

void task()
{

    lli lenNumbers, lenQueries;
    cin >> lenNumbers >> lenQueries;
    vi numbers(lenNumbers);
    for (lli i = 0; i < lenNumbers; i++)
    {
        cin >> numbers[i];
    }
    vector<vector<lli>> sparse(lenNumbers, vector<lli>(floor(log2(lenNumbers)) + 1, 0));
    preprocess(sparse, numbers);
    lli a, b;
    vi res;
    for (lli i = 0; i < lenQueries; i++)
    {

        cin >> a >> b;
        a--;
        b--;

        lli l = b - a + 1;
        lli k = log2(l);

        res.emplace_back(min(numbers[sparse[a][k]], numbers[sparse[a + l - pow(2, k)][k]]));
    }

    for(auto r : res) {
        cout<<r<<'\n';
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    task();

    return 0;
}