#include <iostream>
#include <vector>
using namespace std;
        

int main(){
    int n;
    cin >> n;

    vector<int> v(n + 2, 0);

    int maxNum;
    for(int i = 1; i <= n; i++){
        cin >> v[i];
        maxNum = max(maxNum, v[i]);
    }
    vector<long long>dp(maxNum, 0);
    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;

    for(int i = 1; i <= n; i++){

        for(int j = 4; j <= v[i]; j++){
            dp[j] = dp[j - 1] + dp[j - 2] + dp[j - 3];
        }
        cout << dp[v[i]] << endl;
    }
}