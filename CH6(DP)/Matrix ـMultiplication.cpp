#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n + 1);

    for (int i = 0; i <= n; i++) {
        cin >> a[i];
    }

    vector<vector<long long>> dp(n, vector<long long>(n, 0));

    for (int len = 2; len <= n; len++) {
        for (int i = 0; i + len - 1 < n; i++) {
            int j = i + len - 1;

            dp[i][j] = LLONG_MAX;

            for (int k = i; k < j; k++) {
                long long cost =
                    dp[i][k] +
                    dp[k + 1][j] +
                    a[i] * a[k + 1] * a[j + 1];

                dp[i][j] = min(dp[i][j], cost);
            }
        }
    }

    cout << dp[0][n - 1];
}