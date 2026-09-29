#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;

int divide(int dividend, int divisor) {

    if (dividend == INT_MIN && divisor == -1)
        return INT_MAX;

    long long a = dividend;
    long long b = divisor;

    bool negative = (a < 0) ^ (b < 0);

    a = abs(a);
    b = abs(b);

    long long quotient = 0;

    while (a >= b) {
        long long temp = b;
        long long multiple = 1;

        while (a >= (temp << 1)) {
            temp <<= 1;
            multiple <<= 1;
        }

        a -= temp;
        quotient += multiple;
    }

    if (negative)
        quotient = -quotient;

    return (int)quotient;
}

int main() {
    int dividend, divisor;
    cin >> dividend >> divisor;

    cout << divide(dividend, divisor);

    return 0;
}
