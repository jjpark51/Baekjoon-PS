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
    vector<long long> length(n);
    for(int i = 0; i < n; i++){
        length[i] = 1;
        for(int j = 0; j < i; j++){
            if(v[i] < v[j]){
                length[i] = max(length[i], length[j] + 1);
            }
        }
    }

    long long maxNum = 0;
    for(int i = 0; i < n; i++){
        maxNum = max(maxNum, length[i]);
    }
    cout << maxNum << endl;
}

    
