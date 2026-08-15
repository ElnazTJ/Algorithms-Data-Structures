#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<int> w(n);

    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    if (n >= 20) {
        cout << "YAY!";
        return 0;
    }

    set<long long> sums;

    for (long long mask = 1; mask < (1 << n); mask++) {

        long long sum = 0;

        for (int i = 0; i < n; i++) {
            if (mask & (1 << i)) {
                sum += w[i];
            }
        }

        if (sums.count(sum)) {
            cout << "YAY!";
            return 0;
        }

        sums.insert(sum);
    }

    cout << "AWW!";
}