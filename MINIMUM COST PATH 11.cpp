#include <bits/stdc++.h>
using namespace std;

int main() {
    int N, M;
    cin >> N >> M;

    vector<vector<long long>> grid(N, vector<long long>(M));

    for (int i = 0; i < N; i++) {
        for (int j = 0; j < M; j++) {
            cin >> grid[i][j];
        }
    }

    vector<vector<long long>> dp(N, vector<long long>(M));

    dp[0][0] = grid[0][0];

    // First row
    for (int j = 1; j < M; j++) {
        dp[0][j] = dp[0][j - 1] + grid[0][j];
    }

    // First column
    for (int i = 1; i < N; i++) {
        dp[i][0] = dp[i - 1][0] + grid[i][0];
    }

    // Remaining cells
    for (int i = 1; i < N; i++) {
        for (int j = 1; j < M; j++) {

            dp[i][j] = grid[i][j] + min({
                dp[i - 1][j],     // Down
                dp[i][j - 1],     // Right
                dp[i - 1][j - 1]  // Diagonal
            });
        }
    }

    cout << dp[N - 1][M - 1] << endl;

    return 0;
}
