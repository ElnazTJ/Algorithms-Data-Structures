#include <bits/stdc++.h>
using namespace std;

int solve(string s, int start, char c) {

    char current = c;

    for (int i = start; i < s.size(); i += 2) {

        if (s[i] != '?' && s[i] != current) {
            return 0;
        }

        current = (current == 'a') ? 'b' : 'a';
    }

    return 1;
}

int main() {

    string s;
    cin >> s;

    int even_1 = solve(s, 0, 'a');
    int even_2 = solve(s, 0, 'b');

    int even = even_1 + even_2;

    int odd_1 = solve(s, 1, 'a');
    int odd_2 = solve(s, 1, 'b');

    int odd = odd_1 + odd_2;

    cout << even * odd;

    return 0;
}