#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    long long n;
    cin>>n;
    vector <long long> d(n);
    for(long long i=0 ; i<n ; i++){
        cin>>d[i];
    }
    sort(d.begin() , d.end());
    long long sum=0;
    for(long long i=0 ; i<n ; i++){
        if(sum< d[i]){
            sum++;
        }
        
    }
    cout<<sum;
}