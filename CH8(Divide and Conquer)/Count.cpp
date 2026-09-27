#include <bits/stdc++.h>
using namespace std;

int main() {
    int T;
    cin >> T;

    while (T--) {
        int n;
        long long k;
        cin >> n >> k;

        vector<long long> ps(n + 1);
        ps[0] = 0;

        for (int i = 1; i <= n; i++) {
            long long x;
            cin >> x;
            ps[i] = ps[i - 1] + x;
        }

        sort(ps.begin(), ps.end());

        long long ans = 0;

        for (int i = 0; i <= n; i++) {

            auto left = lower_bound(ps.begin(), ps.end(), ps[i] - k);

            auto right = upper_bound(ps.begin(), ps.end(), ps[i] + k);

            long long bad = right - left;

            ans += (n + 1) - bad;
        }

        cout << ans / 2 << '\n';
    }

    return 0;
}