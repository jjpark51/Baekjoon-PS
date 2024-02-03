#include <iostream>
#include <vector>
using namespace std;

int main(){
    int t;
    cin >> t;

    vector<int>v(t);

    for(int i = 0; i < t; i++){
        cin >> v[i];
    }

    long long dp[101];
    dp[0] = 0;
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;

    for(int i = 0; i < v.size(); i++){
        for(int j = 5; j <= v[i]; j++){
            dp[j] = dp[j-1] + dp[j-5];
        }
    }

    for(int i = 0; i < v.size(); i++){
        cout << dp[v[i]] << endl;
    }
}
