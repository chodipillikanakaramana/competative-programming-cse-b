#include <iostream>
#include <vector>
using namespace std;

int maxAscendingSum(vector<int>& arr) {
    int currentSum = arr[0];
    int maxSum = arr[0];

    for (int i = 1; i < arr.size(); i++) {
        if (arr[i] > arr[i - 1]) {
            currentSum += arr[i];
        } else {
            currentSum = arr[i];
        }

        if (currentSum > maxSum) {
            maxSum = currentSum;
        }
    }

    return maxSum;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr(n);

    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    cout << maxAscendingSum(arr);

    return 0;
}
