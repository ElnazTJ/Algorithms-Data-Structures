#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<vector<long long>> a(n, vector<long long>(m));

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    const long long INF = 4e18;

    vector<long long> left(m, INF), right(m, INF);

    right[0] = a[0][0];

    for (int j = 1; j < m; j++) {
        right[j] = right[j - 1] + a[0][j];
    }

    left[0] = a[0][0];

    for (int i = 1; i < n; i++) {
        vector<long long> newleft(m, INF), newright(m, INF);

        for (int j = 0; j < m; j++) {
            long long up = min(left[j], right[j]);

            if (j == 0) {
                newright[j] = up + a[i][j];
            }
            else {
                newright[j] = min(up, newright[j - 1]) + a[i][j];
            }
        }

        for (int j = m - 1; j >= 0; j--) {
            long long up = min(left[j], right[j]);

            if (j == m - 1) {
                newleft[j] = up + a[i][j];
            }
            else {
                newleft[j] = min(up, newleft[j + 1]) + a[i][j];
            }
        }

        left = newleft;
        right = newright;
    }

    cout << right[m - 1];

    return 0;
}