#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, S;
    cin >> n >> S;

    vector<vector<int>> c(n);
    vector<int> total_price(n);
    vector<int> min_c(n);
    vector<int> sz(n);

    for (int i = 0; i < n; i++) {
        cin >> sz[i];

        c[i].resize(sz[i]);

        for (int j = 0; j < sz[i]; j++) {
            cin >> c[i][j];
            total_price[i] += c[i][j];
        }

        if (sz[i] > 0)
            min_c[i] = *min_element(c[i].begin(), c[i].end());
    }

    vector<vector<int>> dp(n + 1, vector<int>(S + 1, 0));
    vector<vector<char>> choice(n + 1, vector<char>(S + 1, '0'));

    for (int i = 1; i <= n; i++) {
        for (int j = 0; j <= S; j++) {

            // هیچ اسباب‌بازی
            dp[i][j] = dp[i - 1][j];
            choice[i][j] = '0';

            // یک اسباب‌بازی
            if (sz[i - 1] > 0 && j >= min_c[i - 1]) {
                int val = dp[i - 1][j - min_c[i - 1]] + 1;

                if (val > dp[i][j]) {
                    dp[i][j] = val;
                    choice[i][j] = '1';
                }
            }

            // کل پکیج
            if (j >= total_price[i - 1]) {
                int val = dp[i - 1][j - total_price[i - 1]]
                          + sz[i - 1];

                if (val > dp[i][j]) {
                    dp[i][j] = val;
                    choice[i][j] = '2';
                }
            }
        }
    }

    string ans(n, '0');

    int j = S;

    for (int i = n; i >= 1; i--) {
        ans[i - 1] = choice[i][j];

        if (choice[i][j] == '1') {
            j -= min_c[i - 1];
        }
        else if (choice[i][j] == '2') {
            j -= total_price[i - 1];
        }
    }

    cout << dp[n][S] << '\n';
    cout << ans << '\n';
}