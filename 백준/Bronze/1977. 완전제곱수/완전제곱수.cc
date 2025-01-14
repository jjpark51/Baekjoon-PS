#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

int main() {

    int m, n;
    vector<int> result;

    cin >> m >> n;

    for(int i = m; i <= n; i++) {        
        for(int j = 1; j <= i; j++){
            if(i % j == 0){
                if(i / j == j){
                    result.push_back(i);
                    break;
                }
            }
        }
    }

    int sum = 0;
    for(int i = 0; i < result.size(); i++){
        sum += result[i];
    }

    if(sum == 0){
        cout << -1;
    }
    else {
        cout << sum << '\n';
        cout << result[0];
    }
}
