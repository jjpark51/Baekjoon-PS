#include <iostream>
#include <vector>
using namespace std;

long long sum[1001][4];
long long v[1001][3];
int main(){

    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        for(int j = 1; j <=3; j++){
            cin >> v[i][j];
        }
    }

    for(int i = 1; i <= n; i++){
        for(int j = 1; j<= 3; j++){
            if(j==1){
                sum[i][j] = min(sum[i-1][2], sum[i-1][3]) + v[i][j];
            }
            else if(j==2){
                sum[i][j] = min(sum[i-1][1], sum[i-1][3]) + v[i][j];
            }
            else if(j==3){
                sum[i][j] = min(sum[i-1][1], sum[i-1][2]) + v[i][j];
            }
        }
    }
    int minNum = 987654321;
    for(int i = 1; i <= 3; i++){
        // cout << sum[n][i] << endl;
        if(sum[n][i] <= minNum){
            minNum = sum[n][i];
        }
    }
    // cout << "Result" << endl;
    cout << minNum << endl;
    
}
