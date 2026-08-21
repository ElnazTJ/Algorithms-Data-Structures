#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<int> p;
bool used[8];
long long ans = 0;

int solve(){
    int cnt = 0;

    for(int i = 0; i < n; i++){
        for(int j = i + 1; j < n; j++){
            if(p[i] > p[j]){
                cnt++;
            }
        }
    }

    return cnt;
}

void build(){
    if(p.size() == n){
        if(solve() == k){
            ans++;
        }
        return;
    }

    for(int i = 1; i <= n; i++){
        if(!used[i]){

            p.push_back(i);
            used[i] = true;

            build();

            used[i] = false;
            p.pop_back();
        }
    }
}

int main(){
    cin >> n >> k;

    build();

    cout << ans;
}