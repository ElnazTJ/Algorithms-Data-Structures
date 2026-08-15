#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;
int main(){

    ios :: sync_with_stdio(false);
    cin.tie(nullptr);

    long long n , k;
    cin>>n>>k;

    vector<long long> C(n);
    for(long long i=0 ; i<n ; i++){
        long long a;
        cin>>a;
        C[i]= a - i*k;
    }

    sort(C.begin() , C.end());

    long long mid=C[n/2];
    long long sum=0;

    for(long long i=0 ; i<n ; i++){
        sum+=llabs(C[i]-mid);
    }
    
    cout<<sum<<"\n";


}