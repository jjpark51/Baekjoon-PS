#include <iostream>
#include <vector>
#include <stack>
using namespace std;


    int v[1001][1001];
    long long dp[1001][1001];
    
int main(){
    int n,m;

    cin >> n >> m;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            cin >> v[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= m; j++){
            dp[i][j] = max(dp[i-1][j-1], max(dp[i-1][j], dp[i][j-1])) + v[i][j];
        }
    }
    cout << dp[n][m] << endl;

}

    
