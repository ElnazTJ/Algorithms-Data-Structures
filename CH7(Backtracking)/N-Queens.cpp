#include <bits/stdc++.h>
using namespace std;

int n, k;
char a[8][8];

bool check(int row, int col) {

    // سطر
    for (int j = 0; j < n; j++) {
        if (a[row][j] == 'Q')
            return false;
    }

    // ستون
    for (int i = 0; i < n; i++) {
        if (a[i][col] == 'Q')
            return false;
    }

    // بالا-چپ
    for (int i = row - 1, j = col - 1;
         i >= 0 && j >= 0;
         i--, j--) {

        if (a[i][j] == 'Q')
            return false;
    }

    // بالا-راست
    for (int i = row - 1, j = col + 1;
         i >= 0 && j < n;
         i--, j++) {

        if (a[i][j] == 'Q')
            return false;
    }

    // پایین-چپ
    for (int i = row + 1, j = col - 1;
         i < n && j >= 0;
         i++, j--) {

        if (a[i][j] == 'Q')
            return false;
    }

    // پایین-راست
    for (int i = row + 1, j = col + 1;
         i < n && j < n;
         i++, j++) {

        if (a[i][j] == 'Q')
            return false;
    }

    return true;
}

int solve(int pos, int cnt) {

    if (cnt == k)
        return 1;

    if (pos == n * n)
        return 0;

    int ans = 0;

    for (int p = pos; p < n * n; p++) {

        int i = p / n;
        int j = p % n;

        if (check(i, j)) {

            a[i][j] = 'Q';

            ans += solve(p + 1, cnt + 1);

            a[i][j] = ' ';
        }
    }

    return ans;
}

int main() {

    cin >> n >> k;

    memset(a, ' ', sizeof(a));

    cout << solve(0, 0);

    return 0;
}