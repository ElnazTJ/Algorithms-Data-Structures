#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int main(){
    int n;
    cin >> n;
    vector<int> A(n);
    
    for(int i = 0; i < n; i++) {
        cin >> A[i];
    }
    vector<int> bad_indices;
    for(int i = 0; i < n; i++){
        if(A[i]!=i+1)
           bad_indices.push_back(i);
    }
    if(bad_indices.size()==2){
        swap(A[bad_indices[0]], A[bad_indices[1]]);

        bool ok=true;
        for(int i = 0; i < n-1; i++){
            if(A[i]>A[i+1]){
                ok=false;
                break;
            }
        }

        if(ok) cout<<"YES";
        else cout<<"NO";
    }
    else cout<<"NO";
}
