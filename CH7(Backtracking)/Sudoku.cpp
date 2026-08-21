#include <bits/stdc++.h>
using namespace std;

int a[9][9];

bool check(int row , int col , int num){

    for(int i=0 ; i<9 ; i++){
        if(a[i][col]==num)
            return false;
    }

    for(int j=0 ; j<9 ; j++){
        if(a[row][j]==num)
            return false;
    }

    int startRow= (row/3)*3;
    int startCol= (col/3)*3;

    for(int i=startRow ; i<startRow+3 ; i++){
        for(int j=startCol ; j<startCol+3 ; j++){
            if(a[i][j]==num)
                return false;
        }
    }

    return true;
}

bool solve(){

    for(int i=0 ; i<9 ; i++){
        for(int j=0 ; j<9 ; j++){

            if(a[i][j]==0){

                for(int num=1 ; num<=9 ; num++){

                    if(check(i , j , num)){

                        a[i][j]=num;

                        if(solve())
                            return true;

                        a[i][j]=0;

                    }
                }

                return false;
            }
        }
    }

    return true;
}

int main(){

    for(int i=0 ; i<9 ; i++){
        for(int j=0 ; j<9 ; j++){
            cin>>a[i][j];
        }
    }

    if(solve()){
    for(int i=0 ; i<9 ; i++){
        for(int j=0 ; j<9 ; j++){
            cout << a[i][j] << " ";
        }
        cout << endl;
    }
}

    else{
       cout << "No solution exists\n";
    }
}