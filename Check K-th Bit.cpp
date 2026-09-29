#include <bits/stdc++.h>
using namespace std;

int main() {
    int n, k;

    cin >> n;
    cin >> k;

    if (n & (1 << k)) {
        cout << 1;
    } else {
        cout << 0;
    }

    return 0;
}
