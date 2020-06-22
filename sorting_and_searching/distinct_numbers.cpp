#include <bits/stdc++.h>

using namespace std;

/*

METHOD 1

void task() {

    int n;
    scanf("%d", &n);

    unordered_set<long int> distinctNumbersSet;

    long int num;

    for(int i = 0; i < n; i++) {

        scanf("%ld", &num);

        distinctNumbersSet.insert(num);

    }

    int distinctNumbers = distinctNumbersSet.size();

    printf("%d\n", distinctNumbers);
    
}

*/

/*

METHOD 2

void task() {

    int n;
    scanf("%d", &n);

    set<long int> distinctNumbersSet;

    long int num;

    for(int i = 0; i < n; i++) {

        scanf("%ld", &num);

        distinctNumbersSet.insert(num);

    }

    int distinctNumbers = distinctNumbersSet.size();

    printf("%d\n", distinctNumbers);
    
}
*/

void task() {

    int n;
    scanf("%d", &n);

    long int numbers[n];

    for(int i = 0; i < n; i++) {
        scanf("%ld", &numbers[i]);
    }

    sort(numbers, numbers+n);

    int distinctNumbers = 1;

    for(int i = 1; i < n; i++) {

        if(numbers[i] != numbers[i-1]) {
            distinctNumbers++;
        }

    }

    printf("%d\n", distinctNumbers);
    
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    task();

    return 0;
}