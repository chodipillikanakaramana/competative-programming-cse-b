#include <iostream>
#include <vector>
using namespace std;

vector<int> mergeSortedArrays(vector<int>& arr1, vector<int>& arr2) {
    int i = 0, j = 0;
    vector<int> result;

    while (i < arr1.size() && j < arr2.size()) {
        if (arr1[i] <= arr2[j]) {
            result.push_back(arr1[i]);
            i++;
        } else {
            result.push_back(arr2[j]);
            j++;
        }
    }

    while (i < arr1.size()) {
        result.push_back(arr1[i]);
        i++;
    }

    while (j < arr2.size()) {
        result.push_back(arr2[j]);
        j++;
    }

    return result;
}

int main() {
    int n;
    cin >> n;

    vector<int> arr1(n);
    for (int i = 0; i < n; i++) {
        cin >> arr1[i];
    }

    int m;
    cin >> m;

    vector<int> arr2(m);
    for (int i = 0; i < m; i++) {
        cin >> arr2[i];
    }

    vector<int> merged = mergeSortedArrays(arr1, arr2);

    for (int num : merged) {
        cout << num << " ";
    }

    return 0;
}
