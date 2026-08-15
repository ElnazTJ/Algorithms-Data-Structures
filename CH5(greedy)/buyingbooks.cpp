#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    long long n , r;
    cin>>n>>r;
    vector <long long> c(n);
    for(long long i=0 ; i<n ; i++){
        cin>>c[i];
    }
    sort(c.begin() , c.end());

    long long k = 0;
    for(long long i=0 ; i<n ; i++){
        if(c[i] <= r){
            r -= c[i];
            k++;
        }
        else{
            break;
        }
    }
    cout<<k;
}