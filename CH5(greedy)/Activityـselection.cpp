#include <bits/stdc++.h>
using namespace std;

int main(){

    long long n;
    cin >> n;

    vector<pair<long long,long long>> v(n);

    for(int i=0;i<n;i++){
        cin >> v[i].first >> v[i].second;
    }

    sort(v.begin(), v.end(), [](auto& a, auto& b){
        return a.second < b.second;
    });


    long long ans = 0;
    long long last = -1;

    for(int i=0;i<n;i++){

        if(v[i].first >= last){
            ans++;
            last = v[i].second;
        }

    }

    cout << ans;

}