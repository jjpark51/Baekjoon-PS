#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main(){
    long long n;
    cin >> n;

    vector<long long>v(n);

    for(int i = 0; i < n; i++){
        cin >> v[i];
    }
    vector<long long> length(n,1);
    vector<int> p(n,-1);
    for(int i = 1; i < n; i++){
        for(int j = 0; j < i; j++){
            if(v[i] > v[j] && length[i] < length[j] + 1){
                length[i] = length[j] + 1;
                p[i] = j;
            }
        }
    }
    vector<long long>maxNum(2,0);
    for(int i = 0; i < n; i++){
        if(maxNum[0] < length[i]){
            maxNum[0] = length[i];
            maxNum[1] = i ;
        }
    }
    cout << maxNum[0] << endl;

    int prevIndex = maxNum[1];
    vector<int> result;
    while (prevIndex != -1) {
        result.push_back(v[prevIndex]);
        prevIndex = p[prevIndex];
    }

    for (int i = result.size() - 1; i >= 0; i--) {
        cout << result[i] << " ";
    }

}

    
