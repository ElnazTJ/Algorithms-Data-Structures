#include <iostream>
#include <vector>
using namespace std;

void subsets(vector<int> &set, vector<int> &sub_set, int k) {
    if (k == set.size()) {
        for (int i = 0; i < sub_set.size(); i++) 
            cout << sub_set[i] << " ";
        cout << endl; 
        return;
    }
    
    subsets(set, sub_set, k + 1);
    
    sub_set.push_back(set[k]); 
    subsets(set, sub_set, k + 1);

    // Backtrack
    sub_set.pop_back(); 
}

int main() {
    int n;
    if (!(cin >> n)) return 0;
    
    vector<int> set(n);
    vector<int> sub_set;

    for (int i = 0; i < n; i++)
        cin >> set[i];

    subsets(set, sub_set, 0);
    return 0;
}