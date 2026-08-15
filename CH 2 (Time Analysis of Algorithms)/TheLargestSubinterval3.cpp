#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int n;
    cin >> n;

    vector<long long> a(n);
    for (int i = 0; i < n; ++i) {
        cin >> a[i];
    }

    long long ans = -4e18; 

    for (int l = 0; l < n; ++l) {
        long long current_sum = 0;
        
        for (int r = l; r < n; ++r) {
            current_sum += a[r];
            
            if (current_sum > ans) {
                ans = current_sum;
            }
        }
    }

    cout << ans << "\n";

    return 0;
}
