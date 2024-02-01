#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(){
    int n = 0;
    cin >> n;
    int fact = 1;
    for(int i = n; i > 0; i--){
        fact = fact * i;
    }
    if(n == 0){
        cout << 1;
    }
    else {
        cout << fact;
    }
}