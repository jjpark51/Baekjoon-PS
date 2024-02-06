#include <iostream>
#include <vector>
using namespace std;
    
    vector<long long>dp(1001);
int main(){
    int n;
    cin >> n;
    
    vector<long long>v(1001);
    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }

    for(int i = 1; i <= n ;i++){
        for(int j = 1; j < i; j++){
            if(v[j] >= i - j){
                dp[i] = dp[j] + 1;
                break;
            }
        }
        if(dp[i] == 0 && i != 1){
            dp[i] = -1;
        }
    }

    // for(int i = 1; i <= n; i++){
    //     cout << dp[i] << " ";
    // }

    cout << dp[n];

}



    
