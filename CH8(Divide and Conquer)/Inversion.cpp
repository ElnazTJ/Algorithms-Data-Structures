#include <bits/stdc++.h>
using namespace std;

long long mergeAndCount(vector<long long> &a , int l , int mid , int r){
    vector <long long> temp;
    int i = l , j = mid+1;
    long long count = 0;

    while(i<=mid && j<=r){
        if(a[i]<=a[j]){
            temp.push_back(a[i]);
            i++;
        }
        else{
            temp.push_back(a[j]);
            count += (mid-i+1);
            j++;
        }
    }

    while(i<=mid){
        temp.push_back(a[i]);
        i++;
    }

    while(j<=r){
        temp.push_back(a[j]);
        j++;
    }

    for(int i=l ; i<=r ; i++){
        a[i] = temp[i-l];
    }

    return count;
}

long long mergeSort(vector<long long> &a , int l , int r){
    if(l>=r) return 0;
    int mid = (l+r)/2;
    long long count = 0;
    count += mergeSort(a,l,mid);
    count += mergeSort(a,mid+1,r);
    count += mergeAndCount(a,l,mid,r);
    return count;
}

int main(){
    int n;
    cin>>n;
    vector <long long> a(n);
    for(int i=0; i<n ;i++){
        cin >> a[i];
    }

    cout<<mergeSort(a,0,n-1);
}