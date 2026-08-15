#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    int dp[n + 1] = {};
    dp[0] = 1;

    for (int i = 1; i <= n; i++) {
        dp[i] += dp[i - 1];

        if (i >= 2) {
            dp[i] += dp[i - 2];
        }

        if (i >= 5) {
            dp[i] += dp[i - 5];
        }
    }

    cout << dp[n];
}