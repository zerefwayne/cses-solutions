#include <bits/stdc++.h>

using namespace std;

void task()
{

    long int n, m, k;
    scanf("%ld %ld %ld", &n, &m, &k);

    long int applicants[n];
    long int apartments[m];

    for (int i = 0; i < n; i++)
    {
        scanf("%ld", &applicants[i]);
    }

    for (int i = 0; i < m; i++)
    {
        scanf("%ld", &apartments[i]);
    }

    sort(applicants, applicants + n);
    sort(apartments, apartments + m);

    long int currentApplicant = 0;
    long int currentApartment = 0;
    long int allotedApplicants = 0;

    while (currentApplicant < n && currentApartment < m)
    {
        
        if (abs(applicants[currentApplicant] - apartments[currentApartment]) <= k)
        {
            allotedApplicants++;
            currentApartment++;
            currentApplicant++;
        } else {
            if(applicants[currentApplicant] > apartments[currentApartment]) {
                currentApartment++;
            } else {
                currentApplicant++;
            }
        }
    }

    printf("%ld\n", allotedApplicants);
}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    task();

    return 0;
}