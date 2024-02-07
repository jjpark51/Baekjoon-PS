#include <iostream>
#include <vector>
using namespace std;
        

int main(){
    long long n;
    cin >> n;

    vector<long long>t(n+1);
    vector<long long>v(n+1);

    for(int i = 1; i <= n; i++){
        cin >> t[i] >> v[i];
    }

    vector<long long>dp(n+2, 0);

    for(int i = 1; i <= n; i++){
        dp[i+1] = max(dp[i + 1], dp[i]);

        if(i + t[i] <= n + 1){
            dp[i + t[i]] = max(dp[i + t[i]], dp[i] + v[i]);
        }
    }

    // long long maxSum = 0;
    // for(int i = 1; i <= n; i++){
    //     if(t[i] <= n - i + 1){
    //         long long index = i;
    //         long long temp = 0;
    //         while(index <= n && t[index] <= n - index + 1) {
    //             temp += v[index];
    //             maxSum = max(maxSum, temp);
    //             // cout << "tindex" << endl;
    //             // cout << index << " "<< t[index] << endl; 
    //             if(t[index] == 1){
    //                 index = index + 1;
    //             }
    //             else {
    //                 index = t[index] + index;
    //             }


            
    //             // cout << "temp: "<< endl;
    //             // cout << temp << endl;
    //         }
    //         // cout << "index is " << i << endl;
    //         // cout << maxSum << endl;
    //     }
    // }

    cout << dp[n + 1] << endl;


}



    
