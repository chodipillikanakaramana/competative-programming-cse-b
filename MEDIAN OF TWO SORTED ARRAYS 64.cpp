#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;

    vector<int> a(n), b(m);

    for (int i = 0; i < n; i++)
        cin >> a[i];

    for (int i = 0; i < m; i++)
        cin >> b[i];

    int total = n + m;
    int i = 0, j = 0;

    int prev = 0, curr = 0;

    // We only need to go up to the middle
    for (int k = 0; k <= total / 2; k++) {
        prev = curr;

        if (i < n && (j >= m || a[i] <= b[j])) {
            curr = a[i];
            i++;
        }
        else {
            curr = b[j];
            j++;
        }
    }

    cout << fixed << setprecision(1);

    if (total % 2 == 1) {
        cout << (double)curr;
    }
    else {
        cout << (prev + curr) / 2.0;
    }

    return 0;
}
