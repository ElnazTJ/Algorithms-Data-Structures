#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007;

int main() {
    int q;
    cin >> q;

    vector<int> Q(q);
    int maxN = 0;

    for (int i = 0; i < q; i++) {
        cin >> Q[i];
        maxN = max(maxN, Q[i]);
    }

    vector<long long> f(maxN + 1);

    f[0] = 1;
    if (maxN >= 1) f[1] = 1;
    if (maxN >= 2) f[2] = 1;
    if (maxN >= 3) f[3] = 2;

    for (int i = 4; i <= maxN; i++) {
        f[i] = (f[i-1] + f[i-2] + f[i-3] - f[i-4]) % MOD;

        if (f[i] < 0)
            f[i] += MOD;
    }

    for (int i = 0; i < q; i++) {
        cout << f[Q[i]] << '\n';
    }
}