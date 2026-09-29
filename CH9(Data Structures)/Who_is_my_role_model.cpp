#include <bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin >> n;
    vector<int> a(n+1);
    vector<int> in_degree(n+1 , 0);

    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        in_degree[a[i]]++;
    }

    queue<int> q;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] == 0) {
            q.push(i);
        }
    }

    while (!q.empty()){
        int u = q.front();
        q.pop();
        int v = a[u];
        in_degree[v]--;
        if (in_degree[v] == 0) {
            q.push(v);
        }
    }

    vector<int> result;
    for (int i = 1; i <= n; i++) {
        if (in_degree[i] > 0) {
            result.push_back(i);
        }
    }
    cout << result.size() << endl;
    for (int x : result) {
        cout << x << " ";
    }
}