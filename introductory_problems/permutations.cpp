#include <bits/stdc++.h>

using namespace std;

void task() {

    int num;
    scanf("%d", &num);

    if(num == 3 || num == 2) {
        printf("NO SOLUTION\n");
        return;
    }

    for(int i = 2; i <= num; i += 2) {
        printf("%d ", i);
    }

    for(int i = 1; i <= num; i += 2) {
        printf("%d ", i);
    }

    printf("\n");
    
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    task();

    return 0;
}