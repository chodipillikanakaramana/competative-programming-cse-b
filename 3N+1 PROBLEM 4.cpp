#include <iostream>
#include <algorithm>
using namespace std;

int cycleLength(long long n) {
    int count = 1;

    while (n != 1) {
        if (n % 2 == 0)
            n /= 2;
        else
            n = 3 * n + 1;

        count++;
    }

    return count;
}

int main() {
    int i, j;
    cin >> i >> j;

    int start = min(i, j);
    int end = max(i, j);

    int maxCycle = 0;

    for (int num = start; num <= end; num++) {
        maxCycle = max(maxCycle, cycleLength(num));
    }

    cout << i << " " << j << " " << maxCycle;

    return 0;
}
