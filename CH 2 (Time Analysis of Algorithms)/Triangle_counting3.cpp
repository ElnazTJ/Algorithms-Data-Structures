#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int n;
    cin >> n;
    long long ans=0;
    for(int a=1 ; a<=n/3 ; a++ ){
        int  upper_bound= (n-3*a)/2;
        int  lower_bound= n/2-2*a+1;
        if(upper_bound>= lower_bound)
            ans=ans+ upper_bound - max(0 , lower_bound) +1;

    }
    cout<<ans;

}