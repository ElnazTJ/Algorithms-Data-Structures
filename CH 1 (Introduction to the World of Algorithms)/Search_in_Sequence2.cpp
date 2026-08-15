#include <iostream>
#include <algorithm>
using namespace std;
int main(){

    ios:: sync_with_stdio(false);
    cin.tie(nullptr);

    int n , q;
    cin>>n>>q;
    
    int A[n];
    for(int i=0 ; i<n ; i++){
        cin>>A[i];
    }

    sort(A , A+n);

    while(q--){
        int x;
        cin>>x;
        cout<<lower_bound(A , A+n , x)-A<<"\n";
    }
    return 0;
}
