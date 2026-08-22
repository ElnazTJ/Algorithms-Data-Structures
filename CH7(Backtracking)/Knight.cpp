#include <bits/stdc++.h>
using namespace std;

int n, k;

bool visited[10][10];

int dr[] = {2, 2, -2, -2, 1, 1, -1, -1};
int dc[] = {1, -1, 1, -1, 2, -2, 2, -2};

void solve(int row, int col, int cnt) {

    if (cnt == k) {
        visited[row][col] = true;
        return;
    }

    for (int i = 0; i < 8; i++) {

        int nr = row + dr[i];
        int nc = col + dc[i];

        if (nr >= 0 && nr < n && nc >= 0 && nc < n) {
            solve(nr, nc, cnt + 1);
        }
    }
}

int main() {

    cin >> n >> k;

    solve(0, 0, 0);

    int ans = 0;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (visited[i][j])
                ans++;
        }
    }

    cout << ans;

    return 0;
}