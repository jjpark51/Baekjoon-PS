#include <iostream>
#include <vector>
using namespace std;
    
int main(){
    int N, K;
    cin >> N >> K;

    vector<int> weights(N);
    vector<int> values(N);

    for (int i = 0; i < N; i++) {
        cin >> weights[i] >> values[i];
    }

    vector<vector<int>> dp(N + 1, vector<int>(K + 1, 0));

        for (int i = 1; i <= N; i++) {
            for (int w = 1; w <= K; w++) {
                if (weights[i - 1] <= w) {
                    dp[i][w] = max(dp[i - 1][w], values[i - 1] + dp[i - 1][w - weights[i - 1]]);
                } else {
                    dp[i][w] = dp[i - 1][w];
                }
            }
        }

        cout << dp[N][K];
}