#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    long long n, k;
    cin >> n >> k;

    vector<pair<long long,long long>> v(n); // {b, a}

    for (int i = 0; i < n; i++) {
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end()); // sort by b

    priority_queue<long long> pq;
    int i = 0;

    while (true) {
        while (i < n && v[i].first <= k) {
            pq.push(v[i].second - v[i].first);
            i++;
        }

        if (pq.empty()) break;

        long long best = pq.top();
        pq.pop();

        if (best <= 0) break;

        k += best;
    }

    cout << k << "\n";
}