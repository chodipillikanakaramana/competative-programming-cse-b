#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<double> arr(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    // Check whether all values are in [0, 1)
    bool fractional = true;

    for (int i = 0; i < N; i++) {
        if (arr[i] < 0 || arr[i] >= 1) {
            fractional = false;
            break;
        }
    }

    if (fractional) {
        // Bucket sort for [0, 1)
        vector<vector<double>> buckets(N);

        for (int i = 0; i < N; i++) {
            int index = arr[i] * N;
            buckets[index].push_back(arr[i]);
        }

        for (int i = 0; i < N; i++) {
            sort(buckets[i].begin(), buckets[i].end());
        }

        cout << fixed << setprecision(2);

        for (int i = 0; i < N; i++) {
            for (double x : buckets[i]) {
                cout << x << " ";
            }
        }
    }
    else {
        // For integer-style input
        sort(arr.begin(), arr.end());

        for (int i = 0; i < N; i++) {
            if (arr[i] == (int)arr[i])
                cout << (int)arr[i];
            else
                cout << fixed << setprecision(2) << arr[i];

            if (i != N - 1)
                cout << " ";
        }
    }

    return 0;
}
