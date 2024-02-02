#include <stdio.h>
#include <string>
#include <iostream>

using namespace std;

int main(){

    int T;
    cin >> T;
    cin.ignore();

    for(int i = 0; i < T; i++) {
        int R = 0;
        string s;
        cin >> R >> s;

        string result = "";
        for(int i = 0 ; i < s.size(); i++){
            for(int j = 0; j < R; j++){
                result += s[i];
            }
        }
        cout << result << endl;
    }
}