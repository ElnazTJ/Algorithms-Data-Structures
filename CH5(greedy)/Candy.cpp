#include <bits/stdc++.h>

using namespace std;

int main(){
    long long c, n;
    cin >> n >> c;

    priority_queue<long long> pq;

    for(long long i = 0; i < n; i++){
        long long x;
        cin >> x;
        pq.push(x);
    }

    while(c > 0 && !pq.empty())
    {
        long long x = pq.top();
        pq.pop();

        long long d = min(c, max(0LL, x - c));
        c -= d;
    }
    cout<<c;
}