#include <bits/stdc++.h>

using namespace std;

typedef long int li;
typedef long long int lli;
typedef vector<long long int> vlli;
typedef vector<int> vi;
typedef stack<long long int> slli;

void task()
{

    lli lenSongs;
    cin >> lenSongs;

    vector<int> songs(lenSongs);

    for (lli i = 0; i < lenSongs; i++)
    {
        cin >> songs[i];
    }

    map<lli, lli> location;

    lli r = 0;
    lli l = 0;

    lli currentStreak = 0;
    lli maxStreak = 0;

    while (r < lenSongs)
    {

        lli song = songs[r];

        if (location.find(songs[r]) == location.end() || location[songs[r]] == 0)
        {
            currentStreak++;
            maxStreak = max(maxStreak, currentStreak);
            location[songs[r]]++;
            r++;
        }
        else
        {
            currentStreak--;
            location[songs[l]]--;
            l++;
        }
    }

    cout << maxStreak << '\n';
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    task();

    return 0;
}