#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1e9 + 7;

int main() {
    int q;
    cin >> q;

    vector<pair<int, int>> queries(q);

    int max_n = 0;

    for (int i = 0; i < q; i++) {
        int n, r;
        cin >> n >> r;

        queries[i] = {n, r};
        max_n = max(max_n, n);
    }

    vector<vector<long long>> dp(max_n + 1,
                                 vector<long long>(max_n + 1, 0));

    for (int n = 0; n <= max_n; n++) {
        dp[n][0] = 1;
        dp[n][n] = 1;
    }

    for (int n = 1; n <= max_n; n++) {
        for (int r = 1; r < n; r++) {
            dp[n][r] =
                (dp[n - 1][r - 1] + dp[n - 1][r]) % MOD;
        }
    }

    for (auto [n, r] : queries) {
        if (r > n)
            cout << 0 << '\n';
        else
            cout << dp[n][r] << '\n';
    }

    return 0;
}