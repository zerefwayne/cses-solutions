#include <bits/stdc++.h>

using namespace std;

void task() {

    string s;
    getline(cin, s);

    uint longestSequenceLength = 0;
    uint currentSequenceLength = 1;

    for(uint i = 1; i < s.length(); i++) {
        if(s[i] == s[i-1]) {
            currentSequenceLength++;
        } else {
            longestSequenceLength = max(longestSequenceLength, currentSequenceLength);
            currentSequenceLength = 1;
        }
    }

    longestSequenceLength = max(longestSequenceLength, currentSequenceLength);

    printf("%d\n", longestSequenceLength);


}

int main() {

    ios::sync_with_stdio(0);
    cin.tie(0);

    task();

    return 0;
}