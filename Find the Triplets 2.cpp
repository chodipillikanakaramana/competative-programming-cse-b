#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;

    vector<long long> arr(N);

    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }

    long long X;
    cin >> X;

    sort(arr.begin(), arr.end());

    bool found = false;

    for (int i = 0; i < N - 2; i++) {

        // Skip duplicate first elements
        if (i > 0 && arr[i] == arr[i - 1]) {
            continue;
        }

        int left = i + 1;
        int right = N - 1;

        while (left < right) {

            long long sum = arr[i] + arr[left] + arr[right];

            if (sum == X) {
                cout << arr[i] << " "
                     << arr[left] << " "
                     << arr[right] << endl;

                found = true;

                // Skip duplicates
                long long leftValue = arr[left];
                long long rightValue = arr[right];

                while (left < right && arr[left] == leftValue) {
                    left++;
                }

                while (left < right && arr[right] == rightValue) {
                    right--;
                }
            }
            else if (sum < X) {
                left++;
            }
            else {
                right--;
            }
        }
    }

    if (!found) {
        cout << "No Triplet Found";
    }

    return 0;
}
