#include <bits/stdc++.h>
using namespace std;

int partition(vector<long long> &a , int l , int r){

    int ls=l;
    int pivot=a[l];

    for(int i=l+1 ; i<=r ; i++){
        if(a[i]<= pivot){
            ls++;
            swap(a[i] , a[ls]);
        }
    }
    swap(a[l] , a[ls]);

    return ls;

}

void QuickSort(vector<long long> &a , int l , int r){
    if(l>=r) return;
    int ls=l;

    cout<<a[l]<<" ";

    int p=partition( a ,  l ,  r);
    QuickSort(a , l , p-1);
    QuickSort(a , p+1 , r);    
}

int main(){
    int n;
    cin>>n;
    vector <long long> a(n);

    for(int i=0 ; i<n ;i++){
        cin>>a[i];
    }

    QuickSort(a , 0 , n-1);
    cout << "\n";
}