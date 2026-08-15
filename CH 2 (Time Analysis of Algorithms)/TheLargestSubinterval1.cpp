#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    vector<long long> a(n+1);
    for(int i = 1; i <= n; i++)
        cin >> a[i];

    long long ans = LLONG_MIN;

    for(int r = 1; r <= n; r++) {
        for(int l = 1; l <= r; l++) {

            long long sum = 0;

            for(int i = l; i <= r; i++) {
                sum += a[i];
            }

            if(sum > ans)
                ans = sum;
        }
    }

    cout << ans << endl;
}
