#include <bits/stdc++.h>
using namespace std;

int main() {
    int n;
    cin >> n;

    long long w[n];

    for (int i = 0; i < n; i++) {
        cin >> w[i];
    }

    priority_queue<long long, vector<long long>, greater<long long>> pq;

    for (int i = 0; i < n; i++) {
        pq.push(w[i]);
    }

    long long ans = 0;

    while (pq.size() > 1) {
        long long x = pq.top();
        pq.pop();

        long long y = pq.top();
        pq.pop();

        long long sum = x + y;
        ans += sum;

        pq.push(sum);  
    }

    cout << ans;
}