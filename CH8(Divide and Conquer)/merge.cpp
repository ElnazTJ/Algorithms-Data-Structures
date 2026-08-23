#include <bits/stdc++.h>
using namespace std;

int n, k;
vector<vector<long long>> a;

vector<long long> mergeTwo(vector<long long>& left,
                           vector<long long>& right) {

    vector<long long> result;

    int p1 = 0;
    int p2 = 0;

    while (p1 < left.size() && p2 < right.size()) {

        if (left[p1] < right[p2]) {
            result.push_back(left[p1]);
            p1++;
        }
        else {
            result.push_back(right[p2]);
            p2++;
        }
    }

    while (p1 < left.size()) {
        result.push_back(left[p1]);
        p1++;
    }

    while (p2 < right.size()) {
        result.push_back(right[p2]);
        p2++;
    }

    return result;
}

vector<long long> mergeArrays(int l, int r) {

    if (r - l == 1)
        return a[l];

    int mid = (l + r) / 2;

    vector<long long> left = mergeArrays(l, mid);
    vector<long long> right = mergeArrays(mid, r);

    return mergeTwo(left, right);
}

int main() {

    cin >> n >> k;

    a.resize(k, vector<long long>(n));

    for (int i = 0; i < k; i++)
        for (int j = 0; j < n; j++)
            cin >> a[i][j];

    vector<long long> ans = mergeArrays(0, k);

    for (long long x : ans)
        cout << x << ' ';
}