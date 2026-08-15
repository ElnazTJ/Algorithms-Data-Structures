#include <iostream>
#include <vector>
#include <string>
using namespace std;
 
vector <string> GrayCode(int n){
    if(n==1){
        return {"0" , "1"};
    }

    vector <string> previous  = GrayCode(n-1);
    vector <string> result;

    for(const string &s : previous ){
        result.push_back("0" + s);
    }

    for (auto it=previous.rbegin() ; it!= previous.rend() ; ++it){
        result.push_back("1" + *it);
    }

    return result;
}

int main(){

    int n;
    cin>>n;
    vector<int> set(n);
    for(int i=0 ; i<n ; i++){
        cin>>set[i];
    }

    vector<string> code= GrayCode(n);

    for(const string &i : code){
        for(int j=0 ; j<i.size() ; j++){
            if(i[j]=='1'){
                cout<<set[j]<<" ";
            }
        }
        cout<<endl;
    }
}