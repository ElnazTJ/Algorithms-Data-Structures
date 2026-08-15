#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    long long n;
    cin>>n;
    vector <long long> a(n);
    for(int i=0 ; i<n ; i++){
        cin>>a[i];
    }

    for(int i=0 ; i<n ; i++){
        int min=i;
        for(int j=i ; j<n ; j++){
            if(a[min]> a[j]){
                min=j;
            }
        }
        swap(a[i] , a[min]);
    }
    for(int i=0 ; i<n ; i++){
        cout<<a[i]<<" ";
    }

}