#include <iostream>
#include <vector>
#include <cmath>
#include <climits>

using namespace std;

long long get_min_diff(const vector<int> &set, int k, long long current_sum, long long total_sum) {
    if (k == set.size()) {
        return abs(total_sum - 2 * current_sum);
    }

    long long exclude = get_min_diff(set, k + 1, current_sum, total_sum);

    long long include = get_min_diff(set, k + 1, current_sum + set[k], total_sum);

    return min(exclude, include);
}

int main() {
    int n;
    if (!(cin >> n)) return 0;

    vector<int> set(n);
    long long total_sum = 0;

    for (int i = 0; i < n; i++) {
        cin >> set[i];
        total_sum += set[i];
    }

    cout << get_min_diff(set, 0, 0, total_sum) << endl;

    return 0;
}