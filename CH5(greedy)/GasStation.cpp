#include <iostream>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    long long n, k, L;
    if (!(cin >> n >> k >> L)) return 0;

    vector<long long> d(n + 2);
    d[0] = 0; // مبدا
    for (int i = 1; i <= n; i++) {
        cin >> d[i];
    }
    d[n + 1] = L; 

    for (int i = 0; i <= n; i++) {
        if (d[i + 1] - d[i] > k) {
            cout << -1 << "\n";
            return 0;
        }
    }

    vector<int> stops;
    int current_station = 0; 

    for (int i = 1; i <= n + 1; i++) {
        if (d[i] - d[current_station] > k) {
            stops.push_back(i - 1);
            current_station = i - 1; 
        }
    }

    cout << stops.size() << "\n";
    for (int i = 0; i < stops.size(); i++) {
        cout << stops[i] << (i == stops.size() - 1 ? "" : " ");
    }
    cout << "\n";

    return 0;
}