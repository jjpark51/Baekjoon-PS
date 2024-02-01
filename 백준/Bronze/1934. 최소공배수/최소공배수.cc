#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int gcd(int a, int b) {
    int c = a % b;
    while(c != 0){
        a = b;
        b = c;
        c = a % b;
    }
    return b;
}
int main(){
    int T = 0;

    cin >> T;
    cin.ignore();

    for(int i = 0 ; i < T; i++){
        int a = 0, b = 0;
        cin >> a >> b;

        cout << (a *b) / gcd(a,b) << endl;
    }
}