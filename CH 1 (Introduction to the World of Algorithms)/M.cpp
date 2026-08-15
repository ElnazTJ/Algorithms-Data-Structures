#include <iostream>
#include <algorithm>
#include <cmath>
using namespace std;

int main(){
    int n;
    cin >> n;

    long long A[n];
    for(int i = 0; i < n; i++){
        cin >> A[i];
    }

    sort(A, A + n);

    long long mid = A[(n-1)/2];


    long long sum = 0;
    for(int i = 0; i < n; i++){
        sum += llabs(A[i] - mid);
    }

    cout << mid << " " << sum << "\n";
}
