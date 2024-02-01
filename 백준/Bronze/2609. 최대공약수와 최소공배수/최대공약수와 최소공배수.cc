#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> v;

    for(int i = 0; i < 2; i++){
        int temp = 0;
        cin >> temp;
        v.push_back(temp);
    }

    int gcd = 0;
    for(int i = 1; i <= min(v[0],v[1]); i++){
        if(v[0] % i == 0 && v[1] % i == 0){
            gcd = max(gcd, i);
        }
    }

    int gcm = 0;
    int counter = 1;

    while(1) { 
        if(counter % v[0] == 0 && counter % v[1] == 0){
            gcm = counter;
            break;
        }
        counter++;
    }

    cout << gcd << endl;
    cout << gcm << endl;
}