#include <iostream>
#include <vector>
using namespace std;

int main(){
    long long n; 
    cin >> n;

    vector<long long>v(n);

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }


        vector<long long>dp(n,0);

            for(int i = 0; i < n ; i++){
                dp[i] = v[i];
                for(int j = 0; j < i; j++){
                    if(v[j] < v[i] && dp[j] + v[i] > dp[i]){
                        dp[i] = dp[j] + v[i];
                    }
                }
            }
            long long maxSum = 0;
            for(int i = 0; i < n; i++ ){
                maxSum = max(maxSum, dp[i]);
            }
            cout << maxSum;
}

    
