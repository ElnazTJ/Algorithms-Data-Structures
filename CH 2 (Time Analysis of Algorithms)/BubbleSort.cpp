#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    long long n;
    cin>>n;
    vector <long long> a(n);
    for(int i=0; i<n ; i++){
        cin>>a[i];
    }

    for(int i=0; i<n ; i++){
        for(int j=0; j<n-1 ; j++){
            if(a[j]>a[j+1]){
                swap(a[j] , a[j+1]);
            }
        }
    }

    for(int i=0 ; i<n ; i++){
        cout<<a[i]<<" ";
    }

}
