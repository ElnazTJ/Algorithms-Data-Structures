#include <iostream>
#include <vector>
using namespace std;

int main() {
    long long n;
    cin >> n;
    vector<long long> a(n);

    // Use 0-based indexing
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // Insertion sort (0-based)
    for (int i = 0; i < n; i++) {
        int p = i;
        long long item = a[p];
        while (p > 0 && item < a[p - 1]) {
            a[p] = a[p - 1];
            p = p - 1;
        }
        a[p] = item;
    }

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;

    return 0;
}
