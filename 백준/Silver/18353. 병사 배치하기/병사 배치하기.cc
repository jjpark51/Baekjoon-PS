#include <iostream>
#include <vector>
using namespace std;
    
long long dp[2001];
long long v[2001];
int main(){
    int n;
    cin >> n;

    for(int i = 1; i <= n; i++){
        cin >> v[i];
    }
    vector<long long>length(2001, 1);
    for(int i = 1; i <= n; i++){
        length[i] = 1;
        for(int j = 1; j <= i; j++){
            if(v[i] < v[j]){
                length[i] = max(length[i], length[j] + 1);
            }
        }
    }

    long long maxNum = 0;
    for(int i = 1; i <= n; i++) {
        if(maxNum < length[i]){
            maxNum = length[i];
        }
    }

    cout << n - maxNum << endl;
    


}



    
