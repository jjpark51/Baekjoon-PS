#include <stdio.h>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

int main(){
    string s;
    getline(cin ,s);

    long long counter = 0;
    for(int i = 0; i < s.size(); i++) {
        if(i == 0 && s[i] == ' '){
            continue;
        }
        else if(i == s.size() - 1 && s[i] == ' ' && s[s.size() - 2] != ' '){
            counter++;
            break;
        }
        else if(s[i] == ' '){
            counter++;
        }
        else if(i == s.size() - 1 &&  s[i] != ' '){
            counter++;
        }
    }
    cout << counter << endl;
}