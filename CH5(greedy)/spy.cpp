#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, q;
    string s;
    cin >> n;

    getline(cin, s); 
    for (int i = 0; i < n; i++) {
        getline(cin, s);
    }

    cin >> q;
    getline(cin, s); 

    unordered_set<string> agencies;
    int ans = 0;

    for (int i = 0; i < q; i++) {

        getline(cin, s);
        agencies.insert(s);

        if (agencies.size() == n) {
            ans++;

            agencies.clear();

            agencies.insert(s);
        }
    }
    cout << ans << '\n';
}