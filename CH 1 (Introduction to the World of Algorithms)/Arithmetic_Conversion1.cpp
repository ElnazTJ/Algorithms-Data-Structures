#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;
int main(){
    int n , k;
    cin>>n>>k;
    int A[n];
    for(int i=0; i<n ; i++){
        cin>>A[i];
    }

    int C[n];
    for(int i=0; i<n ; i++){
        C[i]=A[i]-i*k;
    }
    sort(C , C+n);

    int mid=C[n/2];

    int sum=0;
    for(int i=0; i<n ; i++){
        sum+=abs(C[i]-mid);
    }
    cout<<sum<<"\n";


}