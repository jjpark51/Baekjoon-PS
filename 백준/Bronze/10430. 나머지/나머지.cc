#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    vector<int> v;

    for(int i = 0 ; i < 3; i++){
        int temp = 0;
        cin >> temp;
        v.push_back(temp);
    }

    int a = (v[0] + v[1])%v[2];
    int b = ((v[0] % v[2]) + (v[1]% v[2]))% v[2];
    int c = (v[0]*v[1]%v[2]);
    int d = ((v[0]%v[2])*(v[1]%v[2]))%v[2];

    cout << a << endl;
    cout << b << endl;
    cout << c << endl;
    cout << d << endl;
}