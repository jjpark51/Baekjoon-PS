#include <iostream>
#include <vector>
using namespace std;

int main(){
    int n;
    cin >> n;

    int minNum = 1000000;
    int maxNum = -1000000;
    vector<int> v;

    for(int i = 0; i < n; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }

    for(int i = 0; i < n; i++){
        if(maxNum < v[i]){
            maxNum = v[i];
        }
        if(v[i] < minNum){
            minNum = v[i];
        }
    }
    cout <<minNum << " " << maxNum;

}