#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    vector<int> dp(n, 1);
    vector<int> parent(n, -1);

    int best = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (a[j] < a[i] && dp[j] + 1 > dp[i]) {
                dp[i] = dp[j] + 1;
                parent[i] = j;
            }
        }

        if (dp[i] > dp[best]) {
            best = i;
        }
    }

    vector<long long> ans;

    int cur = best;

    while (cur != -1) {
        ans.push_back(a[cur]);
        cur = parent[cur];
    }

    reverse(ans.begin(), ans.end());

    cout << ans.size() << '\n';

    for (long long x : ans) {
        cout << x << ' ';
    }

    return 0;
}