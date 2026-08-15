#include <bits/stdc++.h>
using namespace std;

int main() {

    long long n, V;
    cin >> n >> V;

    vector<pair<long long, long long>> hv(n);

    for (long long i = 0; i < n; i++) {
        cin >> hv[i].first >> hv[i].second;
    }

    sort(hv.begin(), hv.end(), [](auto &a, auto &b) {
        return a.first * b.second > b.first * a.second;
    });

    long double h = 0;

    for (long long i = 0; i < n && V > 0; i++) {

        if (V >= hv[i].second) {
            h += hv[i].first;
            V -= hv[i].second;
        }
        else {
            h += (long double)V / hv[i].second * hv[i].first;
            V = 0;
        }
    }

    cout << fixed << setprecision(4) << h;
}