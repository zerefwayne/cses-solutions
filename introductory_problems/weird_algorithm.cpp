#include <bits/stdc++.h>

using namespace std;

void task()
{
    long long int num;
    scanf("%lld", &num);

    while (num != 1)
    {
        printf("%lld ", num);

        if (num & 1)
        {

            // number is odd
            num = num * 3 + 1;
        }
        else
        {

            // number is even
            num /= 2;
        }
    }

    printf("%lld\n", num);

}

int main()
{

    ios::sync_with_stdio(0);
    cin.tie(0);

    task();

    return 0;
}