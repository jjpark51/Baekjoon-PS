#include <iostream>
#include <vector>
#include <math.h>
using namespace std;


long long sum[501][501];
int v[501][501];

int main(){
    int n;
    cin >> n;


    for(int i = 1; i <= n; i++){
        for(int j = 1; j <=i ;j++){
            cin >> v[i][j];
        }
    }
    sum[1][1] = v[1][1];

    for(int i = 2; i <=n ;i++) {
        for(int j = 1; j <=i; j++){
            sum[i][j] = max(sum[i-1][j], sum[i-1][j-1]) + v[i][j];
        }
    }
    long long maxNum = 0;
    for(int i = 1; i <= n; i++){
        if(maxNum <= sum[n][i]){
            maxNum = sum[n][i];
        }
    }
    cout << maxNum << endl;

}
