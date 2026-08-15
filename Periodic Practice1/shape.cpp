#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<string> pattern;

char solve(int x, int y, int level) {

    if (level == 0) {
        return '.';
    }

    int blockSize = pow(n, level - 1);

    int row = x / blockSize;
    int col = y / blockSize;

    if (pattern[row][col] == '*') {
        return '*';
    }

    x %= blockSize;
    y %= blockSize;

    return solve(x, y, level - 1);
}

int main() {

    cin >> n >> k;

    pattern.resize(n);

    for (int i = 0; i < n; i++) {
        cin >> pattern[i];
    }

    int size = pow(n, k);

    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++) {
            cout << solve(i, j, k);
        }
        cout << endl;
    }
}