#include <bits/stdc++.h>

using namespace std;

void task() {

    long int x, y;
    scanf("%ld %ld", &y, &x);

    x--;
    y--;

    long int c = max(x, y);

    long int ans;

    if(c&1) {

        if(x == c) {

            ans = c*c + 1 + y;

        } else {

            ans = (c+1)*(c+1) - x;

        }

    } else {

        if(x == c) {

            ans = (c+1)*(c+1) - y;

        } else {

            ans = c*c + 1 + x;

        }

    }

    printf("%ld\n", ans);
    
}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    int test;
    scanf("%d", &test);
    while(test--) {
        task();
    }

    return 0;
}