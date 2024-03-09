#include <iostream>
#include <vector>
using namespace std;

int main(){

    int maxNum = -1000000;
    vector<int> v;

    for(int i = 0; i < 9; i++){
        int tmp;
        cin >> tmp;
        v.push_back(tmp);
    }
    int maxIndex = 0;
    for(int i = 0; i < 9; i++){
        if(maxNum < v[i]){
            maxNum = v[i];
            maxIndex= i;
        }

    }
    cout <<maxNum << '\n' << maxIndex + 1;

}