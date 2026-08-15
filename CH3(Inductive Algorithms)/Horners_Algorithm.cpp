#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    long long x;
    if (!(cin >> n >> x)) return 0;

    vector<long long> a(n + 1);
    for (int i = 0; i <= n; ++i) {
        cin >> a[i];
    }

    long long MOD = 1000000007; 
    long long P = 0;

    for (int i = 0; i <= n; ++i) {
        P = (P * x + a[i]) % MOD;
    }

    P = (P % MOD + MOD) % MOD;

    cout << P << "\n";

    return 0;
}
