#include <iostream>
using namespace std;

void solve(string s,int len){
    if(len % 2 != 0){
        int i = 0; 

        for(int i = 0; i < len/2 + 1; i++){
            if(s[len/2 -i] != s[len/2 + i]){
                cout << "no" << '\n';
                return;
            }
        }
    } else{
        int left = len / 2 - 1;
        int right = len / 2;

        for(int i = 0; i < len/2 + 1; i++){
            if(s[left - i] != s[right + i]){
                cout << "no" << '\n';
                return;
            }
        }
    }
    cout << "yes" << '\n';
}

int main() {
    string s;
    
    while(cin >> s){
        if(s == "0"){
            break;
        }
        int len = s.size();

        solve(s, len);
    }
}