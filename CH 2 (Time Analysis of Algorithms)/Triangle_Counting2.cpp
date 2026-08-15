#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    
    long long count = 0; 
    
    for (int a = 1; a <= n / 3; ++a) {
        for (int b = a; b <= (n - a) / 2; ++b) {
            int c = n - a - b;
            
            if (a + b > c) {
                count++;
            }
        }
    }
    
    cout << count << endl;
    return 0;
}
