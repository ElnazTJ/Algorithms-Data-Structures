#include <iostream>
#include <vector>
#include <cmath>
#include <climits>
using namespace std;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n;
    cin>>n;
    vector<long long> set(n);
    long long total_sum = 0;
    for (int i = 0; i < n; i++) {
        cin >> set[i];
        total_sum += set[i];
    }

    long long min_diff = total_sum; 
    long long current_sum = 0;
    long long last_gray = 0;

    long long total_states = 1LL << n;

    for (long long i = 1; i < total_states; i++) {
        long long current_gray = i ^ (i >> 1);
        
        long long changed_bit = current_gray ^ last_gray;
        
        int bit_index = __builtin_ctzll(changed_bit); 

        if ((current_gray >> bit_index) & 1) {
            current_sum += set[bit_index];
        } else { 
            current_sum -= set[bit_index];
        }

        long long diff = abs(total_sum - 2 * current_sum);
        if (diff < min_diff) {
            min_diff = diff;
        }

        last_gray = current_gray;
    }

    cout << min_diff << "\n";
}