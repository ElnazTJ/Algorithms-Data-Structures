#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<long long>> a(n, vector<long long>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    vector<vector<long long>> dp(n, vector<long long>(m));
    vector<vector<char>> parent(n, vector<char>(m));

    // شروع از پایین-چپ
    dp[n - 1][0] = a[n - 1][0];

    // ستون اول: فقط U
    for (int i = n - 2; i >= 0; i--) {
        dp[i][0] = dp[i + 1][0] + a[i][0];
        parent[i][0] = 'U';
    }

    // ردیف آخر: فقط R
    for (int j = 1; j < m; j++) {
        dp[n - 1][j] = dp[n - 1][j - 1] + a[n - 1][j];
        parent[n - 1][j] = 'R';
    }

    // خانه‌های داخلی
    for (int i = n - 2; i >= 0; i--) {
        for (int j = 1; j < m; j++) {

            if (dp[i + 1][j] > dp[i][j - 1]) {
                dp[i][j] = dp[i + 1][j] + a[i][j];
                parent[i][j] = 'U';
            }
            else {
                dp[i][j] = dp[i][j - 1] + a[i][j];
                parent[i][j] = 'R';
            }
        }
    }

    cout << dp[0][m - 1] << '\n';

    string answer;

    int i = 0;
    int j = m - 1;

    while (i != n - 1 || j != 0) {

        if (parent[i][j] == 'U') {
            answer += 'U';
            i++;
        }
        else {
            answer += 'R';
            j--;
        }
    }

    // چون از مقصد به شروع ساخته‌ایم
    reverse(answer.begin(), answer.end());

    cout << answer << '\n';

    return 0;
}