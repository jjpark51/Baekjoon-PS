#include <iostream>
#include <vector>
#include <queue>

using namespace std;
long long n, m;


int main() {
    cin >> m >> n;

    long long sum = 0;
    int flag = 0;
    long long minNum = -1;
    int cnt = 0;

    for(long long i = m; i <= n; i++){
        cnt = 0;
        for(long long j = 1; j <= i; j++){
            if(i % j == 0){
                cnt++;
            }
        }
        if(cnt == 2){
            sum += i;
            if(minNum == -1){
                minNum = i;
            }
            
        }
    }
    if(minNum == -1){
        cout << -1 << endl;
    }
    else {
        cout << sum << endl;
        cout << minNum << endl;
    }
}