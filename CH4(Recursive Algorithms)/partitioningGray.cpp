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
    vector<long long> set(n);
    for(int i=0 ; i<n ; i++){
        cin>>set[i];
    }
    long long total_a=0;
     for(int i=0 ; i<n ; i++){
        total_a += set[i];
    }

    vector<string> code= GrayCode(n);
    vector<vector<long long>> subsets;

    for(const string &i : code){
        vector<long long> subset;
        for(int j=0 ; j<i.size() ; j++){
            if(i[j]=='1'){
                subset.push_back(set[j]);
            }
        }
        subsets.push_back(subset);
    }
    long long min=total_a;

    for(const vector<long long> &s : subsets){
        long long sum=0;
        for(long long elem : s){
            sum += elem;
        }
        long long Difference = abs(total_a - 2*sum);
        if(Difference < min){
            min = Difference;
        }
    }
    cout<<min<<endl;
}