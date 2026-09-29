#include <bits/stdc++.h>
using namespace std;

long long divide(long long x, long long y) {

    if (y == 0) {
        return 0;   // division by zero
    }

    // Determine sign
    bool negative = (x < 0) ^ (y < 0);

    // Work with positive values
    long long a = abs(x);
    long long b = abs(y);

    long long low = 0;
    long long high = a;
    long long ans = 0;

    while (low <= high) {

        long long mid = low + (high - low) / 2;

        // Check b * mid <= a safely
        if (mid <= a / b) {
            ans = mid;
            low = mid + 1;
        }
        else {
            high = mid - 1;
        }
    }

    if (negative) {
        ans = -ans;
    }

    return ans;
}

int main() {

    long long x, y;

    cin >> x >> y;

    if (y == 0) {
        cout << "Division by zero";
    }
    else {
        cout << divide(x, y);
    }

    return 0;
}
