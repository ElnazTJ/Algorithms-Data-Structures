#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin >> n;

    vector<long long> h(n);
    for (auto &x : h)
        cin >> x;

    vector<long long> values = h;
    sort(values.begin(), values.end());
    values.erase(unique(values.begin(), values.end()), values.end());

    for (int i = 0; i < n; i++) {
        h[i] = lower_bound(values.begin(), values.end(), h[i]) - values.begin();
    }

    vector<vector<long long>> dp(n + 1, vector<long long>(n + 1, 0));

    for (int i = 0; i < n; i++)
        dp[i][i + 1] = 1;

    for (int len = 2; len <= n; len++) {
        for (int l = 0; l + len <= n; l++) {
            int r = l + len;

            dp[l][r] = dp[l][r - 1];

            if (h[l] == h[r - 1]) {
                dp[l][r]++;

                for (int x = l + 1; x < r - 1; x++) {
                    if (h[x] >= h[l]) {
                        dp[l][r] += dp[x][r - 1];
                        dp[l][r] %= MOD;
                    }
                }
            }

            dp[l][r] %= MOD;
        }
    }

    long long ans = 0;

    for (int l = 0; l < n; l++) {
        ans += dp[l][n];
        ans %= MOD;
    }

    cout << ans << '\n';

    return 0;
}