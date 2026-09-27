#include <bits/stdc++.h>
using namespace std;

double power(double base, int exp) {

    if (exp == 0)
        return 1;

    if (exp == 1)
        return base;

    double result = power(base, exp / 2);

    if (exp % 2 == 0)
        return result * result;
    else
        return base * result * result;
}

int main() {
    double base;
    int exp;

    cin >> base >> exp;

    cout << fixed << setprecision(3) << power(base, exp);

    return 0;
}