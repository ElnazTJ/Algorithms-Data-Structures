#include <iostream>
#include <vector>
using namespace std;

int n;
vector <int> a;

void genarate(int pos){
    if (pos==n){
        for(int i=0 ; i<n ; i++){
            cout<<a[i]<<" ";
        }
        cout<<endl;
        return;
    }

    for(int i=1 ; i<=n ; i++){
        a[pos]=i;
        genarate(pos+1);
    }
}

int main(){
    cin>>n;
    a.resize(n);
    genarate(0);

}