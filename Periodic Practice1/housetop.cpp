#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main() {
    ll n;
    cin >> n;

    vector<ll> c(n + 1);

    for (ll i = 1; i <= n; i++) {
        cin >> c[i];
    }


    vector<ll> suff(n + 1);

    suff[n] = n;

    for (ll i = n - 1; i >= 1; i--) {
        if (c[i] <= c[suff[i + 1]]) {
            suff[i] = i;
        } else {
            suff[i] = suff[i + 1];
        }
    }

    ll ans = 0;
    ll current = 0;

    while (current < n) {
        ll next = suff[current + 1];

        ans += (next - current) * c[next];

        current = next;
    }

    cout << ans;

    return 0;
}