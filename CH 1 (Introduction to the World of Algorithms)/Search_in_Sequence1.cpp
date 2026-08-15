#include <iostream>
using namespace std;
int main(){
    int n,q;
    cin>>n>>q;
    int A[n];
    for(int i=0; i<n ; i++){
        cin>>A[i];
    }
    int Q[q];
    for(int j=0; j<q ;j++){
        cin>>Q[j];
    }
    int c=0;
    for(int j=0 ;j<q; j++){
        for(int i=0 ; i<n ; i++){
            if(Q[j]>A[i]) c++;
        }
        cout<<c<<endl;
        c=0;
    }

    return 0;

}