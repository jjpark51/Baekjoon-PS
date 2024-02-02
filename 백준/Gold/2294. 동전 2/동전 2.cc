#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

const int INF = 987654321;

int minCoinCount(vector<int>& coins, int k) {
    vector<int> dp(k + 1, INF);

    dp[0] = 0; 

    for (int i = 1; i <= k; i++) {
        for (int coin : coins) {
            if (i - coin >= 0) {
                dp[i] = min(dp[i], dp[i - coin] + 1);
            }
        }
    }

    return (dp[k] == INF) ? -1 : dp[k];
}

int main() {
    int n, k;
    cin >> n >> k;

    vector<int> coins(n);
    for (int i = 0; i < n; i++) {
        cin >> coins[i];
    }

    int result = minCoinCount(coins, k);

    cout << result << endl;

    return 0;
}
