#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool primeNum(vector<int>& v, int i) {
        for(int j = 2; j < v[i]; j++){
            if(v[i] % j == 0){
                 return false;
                }
            }
            if(v[i] == 1){
                return false;
            }
            return true;
}

int main(){
    int N = 0;
    cin >> N;
    vector<int> v;
    for(int i = 0; i < N; i++){
        int temp = 0;
        cin >> temp;
        v.push_back(temp);
    }

    int prime = 0;
    for(int i = 0 ; i < v.size(); i++){
        if(primeNum(v,i)){
            prime++;
        }
    }
    cout << prime;
}