#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int main(){
    int n = 0;
    cin >> n;
    cin.ignore();

    string s;
    getline(cin ,s);

    int sum = 0;
    for(int i = 0 ; i < n; i++){
        sum += s[i] - '0';
    }
    cout << sum << endl;

}