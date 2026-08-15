#include <bits/stdc++.h>
using namespace std;
int main(){
    int c[4];
    for (int i = 0; i < 4; i++) {
        cin >> c[i];
    }

    int eaten[4]={0};
    int pos[4]={0 , 1 , 2 ,3};
    int person=0;

    while(true){
        int section=pos[person];

        c[section]--;
        eaten[person]++;

        if(c[section]==0){
            break;
        }

        for(int i = 0; i < 4; i++){
            pos[i]= (pos[i]+1)%4;
        }
        person= (person+1)%4;
    }
    for (int i = 0; i < 4; i++) {
        cout << eaten[i] << " ";
    }
}