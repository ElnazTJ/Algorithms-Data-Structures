#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, k;
    cin >> n >> k;

    vector<int> c(n);
    for (int i = 0; i < n; i++) cin >> c[i];

    if (k == 1) {
        cout << *max_element(c.begin(), c.end()) << "\n";
        return 0;
    }

    if (k >= 3) {
        cout << *min_element(c.begin(), c.end()) << "\n";
        return 0;
    }

    // k == 2
    vector<int> pref(n), suf(n);

    pref[0] = c[0];
    for (int i = 1; i < n; i++)
        pref[i] = max(pref[i - 1], c[i]);

    suf[n - 1] = c[n - 1];
    for (int i = n - 2; i >= 0; i--)
        suf[i] = max(suf[i + 1], c[i]);

    int ans = INT_MAX;

    for (int i = 0; i < n - 1; i++) {
        ans = min(ans, min(pref[i], suf[i + 1]));
    }

    cout << ans << "\n";

    return 0;
}