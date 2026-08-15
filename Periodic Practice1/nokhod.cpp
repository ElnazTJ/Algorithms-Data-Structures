#include <bits/stdc++.h>
using namespace std;

int main() {
    long long m;
    int n;
    cin >> m >> n;

    long long a[n];
    long long sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum += a[i];
    }

    sort(a, a + n);

    long long x = sum - m;
    long long ans = 0;

    for (int i = 0; i < n; i++) {
        long long remaining = n - i;

        if (a[i] * remaining <= x) {
            long long deficit = a[i];

            ans += deficit * deficit;
            x -= deficit;
        }
        else {
            long long q = x / remaining;
            long long r = x % remaining;

            ans += (remaining - r) * q * q;
            ans += r * (q + 1) * (q + 1);

            break;
        }
    }

    cout << ans;
}