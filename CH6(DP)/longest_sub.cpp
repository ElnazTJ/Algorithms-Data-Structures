#include <bits/stdc++.h>
using namespace std;

int main() {
    string s, p;
    cin >> s >> p;

    int n = s.size();
    int m = p.size();

    vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {

            if (s[i - 1] == p[j - 1]) {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    string answer;

    int i = n;
    int j = m;

    while (i > 0 && j > 0) {

        if (s[i - 1] == p[j - 1]) {
            answer += s[i - 1];
            i--;
            j--;
        }
        else if (dp[i - 1][j] >= dp[i][j - 1]) {
            i--;
        }
        else {
            j--;
        }
    }

    reverse(answer.begin(), answer.end());

    cout << dp[n][m] << '\n';
    cout << answer << '\n';

    return 0;
}