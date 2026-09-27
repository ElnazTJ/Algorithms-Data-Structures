#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin>>s;

    stack<int> st;
    vector<pair<int , int>> matches;

    for(int i=0 ; i<s.size() ; i++){
        if(s[i]=='('){
            st.push(i+1);
        }
        else{
            if(st.empty()){
                cout<<"-1\n";
                return 0; // Invalid parentheses
            }
            int openIndex = st.top();
            st.pop();
            matches.push_back({openIndex, i+1});
        }
    }
    if(!st.empty()){
        cout<<"-1\n";
        return 0; // Invalid parentheses
    }
    for(auto match : matches){
        cout << match.first << " " << match.second <<"\n";
    }   
}