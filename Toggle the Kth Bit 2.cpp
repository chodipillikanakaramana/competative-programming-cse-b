#include <bits/stdc++.h>
using namespace std;

int main() {
    long long N;
    int K;

    cin >> N >> K;

    N = N ^ (1LL << K);

    cout << N;

    return 0;
}
