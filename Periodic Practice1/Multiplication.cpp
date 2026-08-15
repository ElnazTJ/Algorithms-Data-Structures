#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<pair<int, int>> a(n);
    vector<int> b(n);

    for (int i = 0; i < n; i++) {
        cin >> a[i].first;
        a[i].second = i;
    }

    for (int i = 0; i < n; i++) {
        cin >> b[i];
    }

    sort(a.begin(), a.end());

    sort(b.begin(), b.end());

    long long total = 0;
    vector<int> ans(n);

    for (int i = 0; i < n; i++) {
        int index = a[i].second;

        ans[index] = b[i];

        total += 1LL * a[i].first * b[i];
    }

    cout << total << '\n';

    for (int i = 0; i < n; i++) {
        cout << ans[i] << ' ';
    }
}