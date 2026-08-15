#include <iostream>
#include <vector>
using namespace std;

static vector<int> partitionRec(const vector<int>& arr, int pivot, int index) {
    if (index >= static_cast<int>(arr.size())) {
        return {};
    }
    vector<int> result = partitionRec(arr, pivot, index + 1);
    if (arr[index] <= pivot) {
        result.insert(result.begin(), arr[index]);
    } else {
        result.push_back(arr[index]);
    }
    return result;
}

vector<int> partition(const vector<int>& arr, int pivot) {
    return partitionRec(arr, pivot, 0);
}