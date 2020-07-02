#include <bits/stdc++.h>

using namespace std;

typedef long long int lli;
typedef vector<lli> vi;

vi calculateLPS(string pattern)
{

    lli n = pattern.length();

    vi lps(n, 0);

    lli j = 0;

    for (lli i = 1; i < n; i++)
    {

        while (j > 0 && pattern[i] != pattern[j])
        {
            j = lps[j - 1];
        }

        if (pattern[i] == pattern[j])
        {
            j++;
        }

        lps[i] = j;
    }

    return lps;
}

lli strStr(string str, string pattern, vi lps)
{

    lli i = 0;
    lli j = 0;

    lli n = str.length();

    lli count = 0;

    while (i < n)
    {

        if (str[i] == pattern[j])
        {
            i++;
            j++;

            if (j == pattern.length())
            {
                count++;
                i = i - j + 1;
                j = 0;
            }
        }
        else if (j == 0)
        {
            i++;
        }
        else
        {
            j = lps[j - 1];
        }
    }

    return count;
}

void task()
{

    string str;
    string pattern;

    cin >> str;
    cin >> pattern;

    auto lps = calculateLPS(pattern);

    auto count = strStr(str, pattern, lps);
    cout << count << '\n';
}

int main()
{

    ios::sync_with_stdio(false);
    cin.tie(NULL);

    task();

    return 0;
}