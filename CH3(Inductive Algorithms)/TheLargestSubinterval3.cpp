#include <iostream>
#include <math.h>
#include <vector>
using namespace std;
int main (){
    int n;
    cin>>n;
    vector <long long> a(n);
    for(int i=0 ; i<n ; i++){
        cin>>a[i];
    }

    long long current = a[0];
    long long ans= a[0];

    for(int i=1 ; i <n ; i++){
        current= max(a[i] , current+a[i]);
        ans= max(ans , current);
    }

    cout<<ans;
}