#include <iostream>
#include <vector>
using namespace std;
    
int main(){
    int n;
    cin >> n;

    vector<long long> v(n+1);

    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }


    vector<long long>dp(n+1, 0);
    dp[1] = v[1];
    dp[2] = v[1] + v[2];

        for(int i = 3; i<= n; i++){
            dp[i] = max(dp[i - 1], max(dp[i - 2] + v[i], dp[i - 3] + v[i - 1] + v[i]));
        }
        long long maxNum = 0;
        for(int i = 1; i <= n; i++){
            // cout << dp[i] << " ";
            if(maxNum < dp[i]){
                maxNum = dp[i];
            }
        }
        cout << maxNum << endl;
}