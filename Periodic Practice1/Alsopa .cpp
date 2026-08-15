#include <bits/stdc++.h>
using namespace std;

int x, n;

int power(int a, int n) {
    int result = 1;

    for (int i = 0; i < n; i++)
        result *= a;

    return result;
}

int solve(int x, int i) {

    if (x == 0)
        return 1;

    if (x < 0 || power(i, n) > x)
        return 0;

    int ans = solve(x, i + 1);

    ans += solve(x - power(i, n), i + 1);

    return ans;
}

int main() {
    cin >> x >> n;

    cout << solve(x, 1);
}