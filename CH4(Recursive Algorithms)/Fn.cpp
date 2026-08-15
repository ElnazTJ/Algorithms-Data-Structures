#include <iostream>
using namespace std;

int Ffunction (int n){
    if (n==0)  return 5;
     int temp =Ffunction(n-1);
    if (n%2==0) return temp-21;
    else return temp*temp;
}

int main(){
    int n;
    cin>>n;
    cout<< Ffunction(n);
}
