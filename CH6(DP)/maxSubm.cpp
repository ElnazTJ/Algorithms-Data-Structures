#include <bits/stdc++.h>
using namespace std;

int main() {
    long long n, m;
    cin >> n >> m;

    vector<vector<long long>> a(n, vector<long long>(m));

    for(long long i = 0; i < n; i++) {
        for(long long j = 0; j < m; j++) {
            cin >> a[i][j];
        }
    }

    if(n > m) {
        vector<vector<long long>> b(m, vector<long long>(n));

        for(long long i = 0; i < n; i++) {
            for(long long j = 0; j < m; j++) {
                b[j][i] = a[i][j];
            }
        }

        a = b;
        swap(n, m);
    }

    long long answer = LLONG_MIN;

    for(long long top = 0; top < n; top++) {

        vector<long long> temp(m, 0);

        for(long long bottom = top; bottom < n; bottom++) {

            for(long long col = 0; col < m; col++) {
                temp[col] += a[bottom][col];
            }

            long long current = temp[0];
            long long best = temp[0];

            for(long long col = 1; col < m; col++) {
                current = max(temp[col], temp[col] + current);
                best = max(best, current);
            }

            answer = max(answer, best);
        }
    }

    cout << answer;
}