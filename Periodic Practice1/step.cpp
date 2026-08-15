#include <bits/stdc++.h>
using namespace std;

int solve(int n) {
    if (n == 0) {
        return 1;
    }

    if (n < 0) {
        return 0;
    }

    return solve(n - 1) + solve(n - 2) + solve(n - 5);
}

int main() {
    int n;
    cin >> n;

    cout << solve(n);
}