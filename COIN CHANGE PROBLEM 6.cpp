#include <bits/stdc++.h>
using namespace std;

int main() {
    int V, N;
    cin >> V >> N;

    vector<int> coins(N);
    for (int i = 0; i < N; i++) {
        cin >> coins[i];
    }

    const int INF = 1e9;
    vector<int> dp(V + 1, INF);

    dp[0] = 0;

    for (int amount = 1; amount <= V; amount++) {
        for (int coin : coins) {
            if (coin <= amount && dp[amount - coin] != INF) {
                dp[amount] = min(dp[amount],
                                 dp[amount - coin] + 1);
            }
        }
    }

    if (dp[V] == INF)
        cout << -1 << endl;
    else
        cout << dp[V] << endl;

    return 0;
}
