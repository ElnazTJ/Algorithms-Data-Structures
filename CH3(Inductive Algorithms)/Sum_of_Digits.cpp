#include <iostream>
#include <string>

using namespace std;

int main() {
    string number;
    cin >> number;
    long long sum = 0;
    for (char c: number) { sum += int(c - '0'); }
    cout << sum << endl;
}