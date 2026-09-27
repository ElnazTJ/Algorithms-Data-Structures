#include <bits/stdc++.h>
using namespace std;
int main(){
    int q;
    cin >> q;

    stack<string> st;
    st.push("");

    while(q--){
        string command;
        cin >> command;
        string s;
        if(command == "insert"){
            int i;
            char x;
            cin >> i >> x;
            s = st.top();
            s.insert(s.begin() + (i-1), x);
            st.push(s);
        }
        else if(command == "delete"){
            int i;
            cin>>i;
            s = st.top();
            s.erase(s.begin() + (i-1));
            st.push(s);
        }
        else if(command =="undo"){
            st.pop();
        }
    }   

    cout << st.top() << endl;
}