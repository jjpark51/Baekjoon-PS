#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main(){
    long long A, K;

    cin >> A >> K;

    vector<long long> dp(K + 1);

    for(int i = A + 1; i < K+1; i++){
        dp[i] = dp[i - 1] + 1;

        if( i % 2 == 0 && i / 2 >= A){
            dp[i] = min(dp[i], dp[i/2] + 1);
        }
    }
    cout << dp[K] << endl;

}