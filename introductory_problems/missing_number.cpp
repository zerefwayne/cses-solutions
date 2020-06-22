#include <bits/stdc++.h>

using namespace std;

void task() {

    long int n;
    scanf("%ld", &n);

    long int total_sum = 0;

    int num;

    for(int i = 0; i < n-1; i++) {

        scanf("%d", &num);
        total_sum += num;    


    }

    long int expected_sum = (n * (n+1)) / 2;

    int missingNumber = expected_sum - total_sum;

    printf("%d\n", missingNumber);


}

int main() {

    ios::sync_with_stdio(false);
    cin.tie(0);

    task();

    return 0;
}