#include <iostream>
using namespace std;

int dp[1001];
int main() {
    int n;

    cin >> n;
    dp[1] = 0;
    dp[2] = 1;
    dp[3] = 0;

    for(int i = 4; i <= n; i++){
        dp[i] = dp[i - 2];
        // cout << "dp[" << i << "] = ";
        // cout << dp[i] << " " ;
        
    }
    if(dp[n] == 0){
            cout << "SK" << '\n';
        }
        else{
            cout << "CY" << '\n';
        }

}