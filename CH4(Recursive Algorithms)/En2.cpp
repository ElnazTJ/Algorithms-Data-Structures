#include <iostream>
using namespace std;

int Ffunction(int n) {
    if (n == 0) return 5;
    
    int rem = n % 4;
    if (rem == 1) return 25;
    if (rem == 2) return 4;
    if (rem == 3) return 16;
    return -5; // when rem == 0
}


int main(){
    int n;
    cin>>n;
    cout<< Ffunction(n);
}
