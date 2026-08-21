#include <bits/stdc++.h>
using namespace std;

int n;
vector<vector<int>> a;
set<int> chosen;
long long ans = 0;

void solve(int i){
    if(i == n){
        ans++;
        return;
    }

    for(int x : a[i]){
        if(!chosen.count(x)){
            chosen.insert(x);

            solve(i + 1);

            chosen.erase(x);
        }
    }
}

int main(){
    cin >> n;

    a.resize(n);

    for(int i = 0; i < n; i++){
        int len;
        cin >> len;

        for(int j = 0; j < len; j++){
            int x;
            cin >> x;
            a[i].push_back(x);
        }
    }

    solve(0);

    cout << ans;
}